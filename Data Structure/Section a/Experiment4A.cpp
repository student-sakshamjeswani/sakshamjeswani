//Circular Singly Linked List Using Pointers in C++:

#include <iostream>
using namespace std;

class CircularLinkedList {
    class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteNode(int value) {
        if (head == nullptr) return;
        Node* temp = head;
        Node* prev = nullptr;
        if (temp->data == value) {
            if (temp->next == head) {
                delete temp;
                head = nullptr;
            } else {
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            return;
        }
        while (temp->next != head && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data == value) {
            prev->next = temp->next;
            delete temp;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "None" << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtEnd(40);

    cout << "Circular Singly Linked List after insertions:" << endl;
    list.display();

    list.deleteNode(20);

    cout << "\nCircular Singly Linked List after deleting 20:" << endl;
    list.display();

    list.deleteNode(100);

    cout << "\nCircular Singly Linked List after attempting to delete 100:" << endl;
    list.display();

    return 0;
}
