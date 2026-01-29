#include <iostream>

class Node {
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList() : head(nullptr) {}

        void insertAtEnd(int val) {
            Node* newNode = new Node(val);
            if (!head) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void insertAtBeginning(int val) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }

        void display() const {
            Node* temp = head;
            while (temp) {
                std::cout << temp->data << " -> ";
                temp = temp->next;
            }
            std::cout << "nullptr\n";
        }

        void insertSorted(int val) {
            Node* newNode = new Node(val);
            if (!head || head->data >= val) {
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* current = head;
            while (current->next && current->next->data < val) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        void deleteByValue(int val) {
            if (!head) return;

            if (head->data == val) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* current = head;
            Node* previous = nullptr;

            while (current && current->data != val) {
                previous = current;
                current = current->next;
            }

            if (current) {
                previous->next = current->next;
                delete current;
            }
        }

        void deleteAtPosition(int position) {
            if (!head || position < 0) return;

            if (position == 0) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* current = head;
            Node* previous = nullptr;
            int index = 0;

            while (current && index < position) {
                previous = current;
                current = current->next;
                index++;
            }

            if (current) {
                previous->next = current->next;
                delete current;
            }
        }

        void search(int val) const {
            Node* current = head;
            int position = 0;
            while (current) {
                if (current->data == val) {
                    std::cout << "Value " << val << " found at position " << position << ".\n";
                    return;
                }
                current = current->next;
                position++;
            }
            std::cout << "Value " << val << " not found in the list.\n";
        }

        void reverseList() {
            Node* prev = nullptr;
            Node* current = head;
            Node* nextNode = nullptr;

            while (current) {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            }
            head = prev;
        }

        bool hasCycle() const {
            Node* slow = head;
            Node* fast = head;

            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    return true;
                }
            }
            return false;
        }

        Node* findCycleStart() {
            if (!hasCycle()) return nullptr;

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

        void removeCycle() {
            if (!hasCycle()) return;

            Node* slow = head;
            Node* fast = head;

            do {
                slow = slow->next;
                fast = fast->next->next;
            } while (slow != fast);

            slow = head;
            Node* prev = nullptr;

            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            prev->next = nullptr;
        }

        void SortList() {
            if (!head || !head->next) return;

            bool swapped;
            do {
                swapped = false;
                Node* current = head;
                while (current->next) {
                    if (current->data > current->next->data) {
                        std::swap(current->data, current->next->data);
                        swapped = true;
                    }
                    current = current->next;
                }
            } while (swapped);
        }

        ~LinkedList() {
            Node* current = head;
            Node* nextNode;
            while (current) {
                nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display(); // Output: 10 -> 20 -> 30 -> nullptr

    std::cout << "After inserting at beginning:\n";
    list.insertAtBeginning(5);
    list.display(); // Output: 5 -> 10 -> 20 -> 30 -> nullptr

    std::cout << "After inserting in sorted order:\n";
    list.insertSorted(15);
    list.display(); // Output: 5 -> 10 -> 15 -> 20 -> 30 -> nullptr

    std::cout << "After deleting by value 20:\n";
    list.deleteByValue(20);
    list.display(); // Output: 5 -> 10 -> 15 -> 30 ->

    std::cout << "After deleting at position 2:\n";
    list.deleteAtPosition(2);
    list.display(); // Output: 5 -> 10 -> 30 ->

    list.search(10); // Output: Value 10 found at position 1.
    list.search(25); // Output: Value 25 not found in the list.

    std::cout << "After reversing the list:\n";
    list.reverseList();
    list.display(); // Output: 30 -> 10 -> 5 -> nullptr

    std::cout << "Sorting the list:\n";
    list.SortList();
    list.display(); // Output: 5 -> 10 -> 30 -> nullptr 
    return 0;
}

