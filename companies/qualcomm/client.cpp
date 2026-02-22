#include <iostream>
#include <thread>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
 
void attack_server(int id) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    int PORT = 8080;
 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        return;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        return;
    }
 
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return;
    }
 
    read(sock, buffer, 1024);
    std::cout << "Client " << id << " received: " << buffer;
    close(sock);
}

// Client 0 received "Server count is now: 1"
// Client 1 received "Server count is now: 2" 
... Upto 9

int main() {
    int NUM_CLIENTS = 10;
    std::vector<std::thread> threads;
 
    for (int i = 0; i < NUM_CLIENTS; ++i) {
        threads.emplace_back(std::thread(attack_server, i));
    }
 
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
 
    return 0;
}


