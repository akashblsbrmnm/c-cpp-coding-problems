#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* head = NULL;

void display(int n) {
    if (head == NULL || n <= 0) {
        printf("NULL\n");
        return;
    }

    Node* temp = head;

    while (temp != NULL && n > 0) {
        printf("%d", temp->data);
        temp = temp->next;
        n--;

        if (temp != NULL && n > 0)
            printf(" -> ");
    }

    printf(" -> NULL\n");
}
