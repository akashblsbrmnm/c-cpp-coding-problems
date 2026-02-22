#include <iostream>
#include <thread>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <mutex>

std::mutex cout_mutex;  // FIX 1: protect cout from concurrent writes

void attack_server(int id) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    int PORT = 8080;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cerr << "Client " << id << ": socket creation failed\n";
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cerr << "Client " << id << ": invalid address\n";
        close(sock);   // FIX 2: close socket on early exit paths
        return;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cerr << "Client " << id << ": connection failed\n";
        close(sock);   // FIX 2: close socket on early exit paths
        return;
    }

    // FIX 3: check read() return value, null terminate safely
    char buffer[1024] = {0};
    ssize_t bytes_read = read(sock, buffer, sizeof(buffer) - 1); // FIX 4: -1 for null terminator

    if (bytes_read < 0) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cerr << "Client " << id << ": read failed: " << strerror(errno) << "\n";
    } else if (bytes_read == 0) {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cerr << "Client " << id << ": server closed connection\n";
    } else {
        buffer[bytes_read] = '\0'; // FIX 4: explicit null termination
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Client " << id << " received: " << buffer << "\n";
    }

    close(sock);
}

int main() {
    int NUM_CLIENTS = 10;
    std::vector<std::thread> threads;
    threads.reserve(NUM_CLIENTS); // FIX 5: reserve to avoid reallocations

    for (int i = 0; i < NUM_CLIENTS; ++i) {
        threads.emplace_back(attack_server, i); // FIX 6: cleaner emplace_back syntax
    }

    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    return 0;
}

