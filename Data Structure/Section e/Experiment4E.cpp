#include <iostream>
#include <string>
using namespace std;
// Function for Linear Search on array of strings
int linearSearch(string arr[], int n, string target) {
    // Traverse the array
    for (int i = 0; i < n; i++) {
        // If the current element matches the target, return the index
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
void printArray(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    string arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    string target = "cherry";
    // Perform Linear Search
    int result = linearSearch(arr, n, target);
    // Output the result
    if (result != -1) {
        cout << "Element \"" << target << "\" found at index " << result << endl;
    } else {
        cout << "Element \"" << target << "\" not found in the array" << endl;
    }
    return 0;
}
