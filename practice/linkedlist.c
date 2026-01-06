#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

Node* insertAtBeg(Node* head, int value)
{
    Node* newnode = malloc(sizeof(Node));
    newnode -> data = value;
    newnode->next  = head;
    return head;
}

Node* insertAtEnd(Node* head, int value)
{
    Node* newnode = malloc(sizeof(Node));
    newnode->data =value;
    newnode->next = NULL;

    if(head == NULL) {
        newnode->next = head;
        return head;
    }

    Node* curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = newnode;
    return head;
}

Node* deleteByValue(int val)
{
    if(head == NULL) return NULL;

    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    free(curr);
}

void reverse_ll(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr =next;
    }
    head  = prev;
}

int hasCycle()
{
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next != NULL)
    {
        slow= slow->next;
        fast = fast->next;
        if(slow == fast)
            return 1;
    }
    return -1;
}