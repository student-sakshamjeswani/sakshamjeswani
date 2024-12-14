#include <iostream>
using namespace std;
// Function for Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;  // Target found, return its index
        }
        // If target is smaller than mid, ignore the right half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger than mid, ignore the left half
        else {
            left = mid + 1;
        }
    }
    return -1;  // Target is not present in the array
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    // Example sorted array
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Target element to search for
    int target = 10;
    // Perform Binary Search
    int result = binarySearch(arr, n, target);
    // Output the result
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }
    return 0;
}
