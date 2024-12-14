//The implementation of a Stack using Pointers in C++:

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (!newNode) {
            cout << "Stack Overflow\n";
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    
    cout << "Top element is " << stack.peek() << endl;

    stack.pop();
    cout << "Top element after pop is " << stack.peek() << endl;

    stack.push(50);
    cout << "Top element after pushing 50 is " << stack.peek() << endl;

    while (!stack.isEmpty()) {
        cout << "Popping " << stack.peek() << endl;
        stack.pop();
    }

    stack.pop();  // Stack underflow

    return 0;
}
