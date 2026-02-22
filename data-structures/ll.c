#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

Node* insertAtBeginning(int value)
{
    Node* newnode = malloc(sizeof(Node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    return newnode;
}

Node* isnertAtend(int val)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
        return head; 

}

Node *insertAtGivenPos(int val, int pos)
{
    Node* newnode = malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;

    if(pos == 0)
    {
        // Insert at front
        newnode->next = head;
        head = newnode;
        return head;
    }

    Node* curr = head;
    int idx = 0;
    while(curr!=NULL && idx < pos - 1)
    {
        curr = curr->next;
        idx++;
    }

    if(curr == NULL)
    {
        free(newnode);
        return NULL;
    }

    newnode->next =  curr->next;
    curr->next = newnode;
    return head;
}


Node* insertSorted(int val)
{
    Node* newnode =  malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;

    if(head == NULL | val < head->data)
    {
        newnode->next = head;
        head = newnode;
        return newnode;
    }

    Node* curr =  head;
    while (curr!=NULL && val > curr->next->data)
    {
        curr = curr-> next;
    }

    newnode->next = curr->next;
    curr->next = newnode;
    return newnode;
    
}


Node* reverseList()
{
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}


void deleteValue(int val)
{
    if(head == NULL)
    {
        return; // Nothing to delete
    }

    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL && curr->data != val)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    free(curr);
    return;
}

void deleteByPosition(int position)
{

    if(position == 0)
    {
        Node* temp = head;
        head = temp-> next ;
        free(temp);
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    int idx = 0;
    while (curr!=NULL && idx < (position - 1))
    {
        prev = curr;
        curr = curr->next;
        idx++;
    }
    if(curr == NULL)
    {
        return;
    }

    prev-> next = curr->next;
    free(curr);
    
}