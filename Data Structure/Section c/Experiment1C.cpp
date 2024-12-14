//Here is the C++ implementation of a Queue using an Array:
#include <iostream>
using namespace std;
class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
 bool isFull(){ 
 return rear == capacity - 1;
 }
    
 bool isEmpty() {
        return front == -1 || front > rear;
    }
 void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) { 
            front = 0; 
        }
        arr[++rear] = value;
        cout << value << " enqueued to queue" << endl;
    }
void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return; }
        cout << arr[front] << " dequeued from queue" << endl;
        front++;  }
int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }
 void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }   ~Queue() {
        delete[] arr;
    }
};int main() {
    Queue q(5);
     q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.dequeue();
    cout << "Front element is " << q.peek() << endl;
    q.enqueue(60);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}

