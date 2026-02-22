#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

// GLOBAL VARIABLES
static int client_count = 0;

void* handle_client(void* args) {
    int c = *(int *)args;
    free(args);

    int id;
    pthread_mutex_lock(&mut);
    client_count++;
    id = client_count;
    pthread_mutex_unlock(&mut);

    char recv_buf[1024];
    ssize_t bytes = recv(c, recv_buf, sizeof(recv_buf) - 1, 0);

    if (bytes <= 0) {
        close(c);
        return NULL;
    }

    recv_buf[bytes] = '\0';

    printf("Received message from Client %d: %s\n", id, recv_buf);

    close(c);
    return NULL;
}

int main() {
    int server;
    struct sockaddr_in s_addr, c_addr;
    memset(&s_addr, 0, sizeof(s_addr));

    server = socket(AF_INET, SOCK_STREAM, 0);
    if(server < 0) {
        perror("Socket failed\n");
        return 1;
    }
    
    
    int opt = 1; // REUSE THE PORT TO AVOID ADDRESS ALREADY IN USE PROBLEM
    setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(8080);
    s_addr.sin_addr.s_addr = INADDR_ANY;


    if(bind(server, (struct sockaddr*)&s_addr, sizeof(s_addr)) < 0) {
        perror("Bind failed\n");
        return 1;
    }

    listen(server, 5);

    while(1) {
        socklen_t len = sizeof(c_addr);
        int* client_fd = malloc(sizeof(int));
        *client_fd = accept(server, (struct sockaddr*)&c_addr, &len);
        if(*client_fd < 0) {
            perror("Accept failed\n");
            return 1;
        }

        pthread_t t;
        pthread_create(&t, NULL, handle_client, client_fd);
        pthread_detach(t);
    }
    return 0;
}