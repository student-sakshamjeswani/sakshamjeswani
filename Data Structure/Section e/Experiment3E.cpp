#include <iostream>
#include <string>
#include <algorithm>  // for sort()
using namespace std;

// Function to perform Binary Search on the array of strings
int binarySearch(string arr[], int n, string target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If the target is found at mid
        if (arr[mid] == target) {
            return mid;
        }
        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            low = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }
    // Target is not present in the array
    return -1;
}
// Function to print the array of strings
void printArray(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    // Example array of strings
    string arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    // Sort the array first (Binary Search requires sorted array)
    sort(arr, arr + n);
    cout << "Sorted Array: ";
    printArray(arr, n);
    // Target string to search for
    string target = "cherry";
    // Perform Binary Search
    int result = binarySearch(arr, n, target);
    // Output the result
    if (result != -1) {
        cout << "Element \"" << target << "\" found at index " << result << endl;
    } else {
        cout << "Element \"" << target << "\" not found in the array" << endl;
    }
    return 0;
}
