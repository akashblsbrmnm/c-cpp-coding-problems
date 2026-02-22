#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CLIENTS 5

void* conn_to_server(void* args) {
    int id = *(int*)args;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Socket failed");
        return NULL;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    if(inet_pton(AF_INET, "127.0.0.1",
                 &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        return NULL;
    }

    if(connect(sock,
               (struct sockaddr*)&server_addr,
               sizeof(server_addr)) < 0) {
        perror("Connect failed");
        close(sock);
        return NULL;
    }

    char buffer[1024];
    snprintf(buffer, sizeof(buffer),
             "Hello from client thread %d", id);

    send(sock, buffer, strlen(buffer), 0);

    close(sock);
    return NULL;
}

int main() {
    pthread_t threads[MAX_CLIENTS];
    int ids[MAX_CLIENTS];

    for(int i = 0; i < MAX_CLIENTS; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i],
                       NULL,
                       conn_to_server,
                       &ids[i]);
    }

    for(int i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}