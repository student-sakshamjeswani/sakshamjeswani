//Doubly linked List Using Pointers in C++
#include <iostream>
using namespace std;

class DoublyLinkedList {
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;
            Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
  Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }
 void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
}
void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current; }
    }
 void deleteNode(int value) {
        Node* current = head;
        while (current != nullptr && current->data != value) {
            current = current->next;
        }
        if (current == nullptr) return;
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        delete current;
    }
 void displayForward() {
        Node* current = head;
        if (current == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data << " <-> ";
   current = current->next;
        }
        cout << "None" << endl;
    }
 void displayBackward() {
        Node* current = head;
        if (current == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        while (current->next != nullptr) {
            current = current->next;
        }
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "None" << endl;
    }
};
int main() {
    DoublyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtEnd(40);
    cout<< "Doubly Linked List forward display:" << endl;
    list.displayForward();
    cout << "\nDoubly Linked List backward display:" << endl;
    list.displayBackward();
    list.deleteNode(20);
    cout << "\nDoubly Linked List after deleting 20 (forward display):" << endl;
    list.displayForward();
    list.deleteNode(100);
    cout << "\nDoubly Linked List after attempting to delete 100 (forward display):" << endl;
    list.displayForward();
    return 0;
}
