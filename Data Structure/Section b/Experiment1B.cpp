//The implementation of a Stack using an Array in C++:

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    
    cout << "Top element is " << stack.peek() << endl;
    
    stack.pop();
    cout << "Top element after pop is " << stack.peek() << endl;

    stack.push(60);
    cout << "Top element after pushing 60 is " << stack.peek() << endl;
    
    while (!stack.isEmpty()) {
        cout << "Popping " << stack.peek() << endl;
        stack.pop();
    }
    
    stack.pop();  // Stack underflow

    return 0;
}
