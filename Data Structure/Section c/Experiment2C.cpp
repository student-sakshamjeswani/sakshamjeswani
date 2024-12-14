//C++ Code for Queue Using Pointers:
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;  // Both front and rear point to the new node when the queue is empty
        } else {
            rear->next = newNode;  // Link the current rear to the new node
            rear = newNode;        // Move the rear to the new node
        }
        cout << value << " enqueued to queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << temp->data << " dequeued from queue" << endl;
        front = front->next;  // Move front to the next node
        delete temp;          // Free the memory for the dequeued node
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.dequeue();
   cout << "Front element is " << q.peek() << endl;
   q.enqueue(50);
   q.display();
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.dequeue();

    return 0;
}
