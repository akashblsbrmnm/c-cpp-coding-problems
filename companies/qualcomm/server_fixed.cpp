#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <atomic>
#include <mutex>
#include <csignal>

std::atomic<int> client_count = 0;       // FIX 1: atomic to prevent race condition
std::mutex cout_mutex;                    // FIX 2: protect console output
std::vector<std::thread> client_threads; // FIX 3: track threads instead of detaching
std::mutex threads_mutex;                // protect the threads vector itself
int server_fd = -1;                      // global so signal handler can close it

// FIX 4: signal handler for graceful shutdown
void handle_signal(int signal) {
    std::cout << "\nShutting down server...\n";
    if (server_fd != -1) {
        close(server_fd);
        server_fd = -1;
    }
}

void handle_client(int client_socket) {
    // FIX 1: atomic increment - no race condition, no need for sleep
    int current_count = ++client_count;

    std::string msg = "Server count is now: " + std::to_string(current_count) + "\n";

    // FIX 5: check send() return value and handle partial sends
    size_t total_sent = 0;
    while (total_sent < msg.length()) {
        ssize_t sent = send(client_socket, msg.c_str() + total_sent, msg.length() - total_sent, 0);
        if (sent < 0) {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cerr << "send() failed: " << strerror(errno) << "\n";
            break;
        }
        total_sent += sent;
    }

    // FIX 6: check close() return value
    if (close(client_socket) < 0) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cerr << "close() failed: " << strerror(errno) << "\n";
    }
}

int main() {
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);  // FIX 7: socklen_t instead of int
    int PORT = 8080;

    // FIX 4: register signal handlers
    std::signal(SIGINT, handle_signal);
    std::signal(SIGTERM, handle_signal);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Server listening on port " << PORT << "\n";
    }

    while (server_fd != -1) {
        struct sockaddr_in client_address;          // FIX 8: separate struct for client
        socklen_t client_addrlen = sizeof(client_address);

        int new_socket = accept(server_fd, (struct sockaddr *)&client_address, &client_addrlen);

        if (new_socket < 0) {
            if (server_fd == -1) break; // shutdown was triggered, exit cleanly
            perror("accept");
            continue; // FIX 9: don't exit on a single failed accept, keep running
        }

        {
            std::lock_guard<std::mutex> lock(cout_mutex);
            std::cout << "New connection from "
                      << inet_ntoa(client_address.sin_addr)   // log client IP
                      << ":" << ntohs(client_address.sin_port) << "\n";
        }

        // FIX 3: store thread instead of detaching
        {
            std::lock_guard<std::mutex> lock(threads_mutex);
            client_threads.emplace_back(std::thread(handle_client, new_socket));
        }

        // FIX 10: clean up finished threads so vector doesn't grow forever
        {
            std::lock_guard<std::mutex> lock(threads_mutex);
            for (auto it = client_threads.begin(); it != client_threads.end(); ) {
                if (it->joinable()) {
                    it->join();  // non-blocking only if thread is done
                }
                it = client_threads.erase(it);
            }
        }
    }

    // FIX 3: join all remaining threads on shutdown
    std::cout << "Waiting for client threads to finish...\n";
    {
        std::lock_guard<std::mutex> lock(threads_mutex);
        for (auto& t : client_threads) {
            if (t.joinable()) t.join();
        }
    }

    std::cout << "Server shut down cleanly. Total clients served: " << client_count << "\n";
    return 0;
}

