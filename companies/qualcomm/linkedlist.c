#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* head = NULL;
 
void* update_list(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 5; i++) {
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->data = id * 100 + i;
 
        struct Node* temp = head;
        usleep(100); 
        new_node->next = temp;
        head = new_node;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1;
    int id2 = 2;
 
    pthread_create(&t1, NULL, update_list, &id1);
    pthread_create(&t2, NULL, update_list, &id2);
 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
 
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
 
    return 0;
}

