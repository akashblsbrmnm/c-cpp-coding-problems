#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

// Insert at beginning
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode; // New head
}

// Insert at end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insert in sorted order (ascending)
Node* insertSorted(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data < value)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Insert at given position (0-based)
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    for (int i = 0; i < position - 1 && curr != NULL; i++)
        curr = curr->next;

    if (curr == NULL) {
        free(newNode);
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Search a value
void search(int val) {
    printf("Searching for %d...\n", val);
    int pos = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("Found at position: %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found\n");
}

// Delete node by value
void deleteNodeByValue(int val) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    if (curr->data == val) {
        head = curr->next;
        free(curr);
        return;
    }

    while (curr != NULL && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node with value %d not found\n", val);
        return;
    }

    prev->next = curr->next;
    free(curr);
}

// Delete node at position (0-based)
Node* deleteNodeAtPosition(Node* head, int position) {
    if (head == NULL) return NULL;

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    int i = 0;

    while (curr != NULL && i < position) {
        prev = curr;
        curr = curr->next;
        ++i;
    }

    if (curr == NULL) return head;

    prev->next = curr->next;
    free(curr);
    return head;
}

void deleteByNode(Node* node) {
    if (node == NULL || node->next == NULL) {
        printf("Cannot delete this node (NULL or tail node)\n");
        return;
    }

    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}


// Reverse the list
void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Print list
void printList() {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Detect cycle
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    if (head == NULL) return false;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Find loop start
Node* findLoopStart(Node* head) {
    if (!head || !hasCycle(head))
        return NULL;

    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Remove loop
void removeLoop(Node* head) {
    Node* loopStart = findLoopStart(head);
    if (!loopStart) return;

    Node* temp = loopStart;
    while (temp->next != loopStart)
        temp = temp->next;

    temp->next = NULL;
}

// Demo / menu
int main() {
    int choice, value, position;
    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert sorted\n4. Insert at position\n");
        printf("5. Delete by value\n6. Delete at position\n7. Delete by Node\n8. Search\n9. Reverse\n10. Print\n11. Detect cycle\n12. Remove loop\n13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertSorted(head, value);
                break;
            case 4:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                head = insertAtPosition(head, value, position);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNodeByValue(value);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteNodeAtPosition(head, position);
                break;
            case 7: // Delete by node pointer
                printf("Enter value to delete by node pointer: ");
                scanf("%d", &value);
                {
                    Node* temp = head;
                    while (temp != NULL && temp->data != value)
                        temp = temp->next;
                    if (temp == NULL)
                        printf("Node not found\n");
                    else if (temp->next == NULL)
                        printf("Cannot delete tail node by pointer\n");
                    else
                        deleteByNode(temp);
                }
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 9:
                reverseList();
                printf("List reversed\n");
                break;
            case 10:
                printList();
                break;
            case 11:
                if (hasCycle(head))
                    printf("Cycle detected\n");
                else
                    printf("No cycle\n");
                break;
            case 12:
                removeLoop(head);
                printf("Loop removed if existed\n");
                break;
            case 13:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
