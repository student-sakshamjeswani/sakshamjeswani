//Linked list Using Pointers in C++.
#include <iostream>
using namespace std;

class LinkedList {
    class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };  Node* head;
public:
    LinkedList() {
        head = nullptr;    }
        void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void deleteNode(int value) {
        Node* current = head;
        Node* prev = nullptr;
        if (current != nullptr && current->data == value) {
            head = current->next;
            delete current;
            return;
        }
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) return;
        prev->next = current->next;
        delete current;
    }

    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data <<  "->" ;
            current = current->next;
        }
        cout << "None" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtEnd(40);

    cout << "Linked List after insertions:" << endl;
    list.display();

    list.deleteNode(20);

    cout << "\nLinked List after deleting 20:" << endl;
    list.display();

    list.deleteNode(100);

    cout << "\nLinked List after attempting to delete 100:" << endl;
    list.display();

    return 0;
}
