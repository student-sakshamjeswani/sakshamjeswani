//Linked List Implementation using Arrays in Java
#include <iostream>
using namespace std;

// Define the structure of a node in the linked list
struct Node {
    int data;       // Stores the data of the node
    int next;       // Stores the index of the next node (-1 for the last node)
};

class LinkedList {
private:
    Node* arr;      // Array to store nodes
    int size;       // Size of the array (number of elements)
    int head;       // Index of the first node
    int free;       // Index of the next available space in the array

public:
    // Constructor to initialize the LinkedList
    LinkedList(int maxSize) {
        arr = new Node[maxSize];
        size = maxSize;
        head = -1;   // Initially, the list is empty
        free = 0;    // The free index is 0 initially

        // Initialize all nodes to indicate no next element
        for (int i = 0; i < size - 1; ++i) {
            arr[i].next = i + 1;
        }
        arr[size - 1].next = -1;  // Last node points to -1 (end of list)
    }

    // Destructor to clean up memory
    ~LinkedList() {
        delete[] arr;
    }

    // Insert a new element at the end of the linked list
    void insert(int value) {
        if (free == -1) {
            cout << "Error: Linked List is full!" << endl;
            return;
        }

        int newNode = free;  // Get the next free node index
        free = arr[free].next;  // Update the free index
        arr[newNode].data = value;
        arr[newNode].next = -1;  // Initially, the new node points to -1 (end of list)

        // If the list is empty, the new node becomes the head
        if (head == -1) {
            head = newNode;
        } else {
            // Traverse to the last node and add the new node
            int current = head;
            while (arr[current].next != -1) {
                current = arr[current].next;
            }
            arr[current].next = newNode;
        }

        cout << "Inserted " << value << " into the list." << endl;
    }

    // Display the elements of the linked list
    void display() {
        if (head == -1) {
            cout << "The list is empty!" << endl;
            return;
        }

        int current = head;
        cout << "Linked List: ";
        while (current != -1) {
            cout << arr[current].data << " ";
            current = arr[current].next;
        }
        cout << endl;
    }

    // Delete an element from the linked list
    void deleteValue(int value) {
        if (head == -1) {
            cout << "The list is empty!" << endl;
            return;
        }

        int current = head;
        int previous = -1;

        // Search for the node with the given value
        while (current != -1 && arr[current].data != value) {
            previous = current;
            current = arr[current].next;
        }

        if (current == -1) {
            cout << "Value " << value << " not found in the list!" << endl;
            return;
        }

        // If the node to delete is the head
        if (current == head) {
            head = arr[current].next;
        } else {
            arr[previous].next = arr[current].next;
        }

        // Return the deleted node to the free list
        arr[current].next = free;
        free = current;

        cout << "Deleted value " << value << " from the list." << endl;
    }
};

int main() {
    // Create a linked list with a maximum of 10 nodes
    LinkedList list(10);

    // Insert elements into the linked list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    // Display the linked list
    list.display();

    // Delete an element from the linked list
    list.deleteValue(20);

    // Display the linked list after deletion
    list.display();

    // Insert another element
    list.insert(50);

    // Display the linked list after the new insertion
    list.display();

    return 0;
}