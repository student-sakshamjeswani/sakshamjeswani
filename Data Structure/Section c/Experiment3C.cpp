//C++ Code for Circular Queue using Array:
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;   }
bool isFull() {
        return (rear + 1) % capacity == front;
    }
bool isEmpty() {
        return front == -1;
    }
 void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) { 
            front = 0; 
        }
        rear = (rear + 1) % capacity;  // Circular increment
        arr[rear] = value;
        cout << value << " enqueued to queue" << endl;
    }
void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue" << endl;
        if (front == rear) {  // Only one element was in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;  // Circular increment
        }
    }
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
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;  // Circular increment
        }
        cout << arr[rear] << endl;  // Display the last element
    }

    ~CircularQueue() {
        delete[] arr;
    }
};
int main() {
    CircularQueue q(5);  // Queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();  // Display all elements in the queue

    q.dequeue();
    q.dequeue();

    cout << "Front element is " << q.peek() << endl;

    q.enqueue(60);
    q.enqueue(70);

    q.display();  

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
