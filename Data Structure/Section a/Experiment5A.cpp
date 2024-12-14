//Circular Doubly linked list using pointers in c++:
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class CircularDoublyLinkedList {
private:
    Node* head;
public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void displayForward() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayBackward() {
        if (!head) return;
        Node* temp = head->prev;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }

    void deleteNode(int val) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == val) {
                if (temp == head && temp->next == head) {
                    delete temp;
                    head = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head) {
                        head = temp->next;
                    }
                    delete temp;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    ~CircularDoublyLinkedList() {
        if (head) {
            Node* temp = head;
            do {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            } while (temp != head);
        }
    }
};

int main() {
    CircularDoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.displayForward();
    list.displayBackward();
    list.deleteNode(20);
    list.displayForward();
    list.displayBackward();
    return 0;
}
