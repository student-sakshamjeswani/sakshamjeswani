//C++ Code for Factorial Calculation Using Recursion with Stack States:
#include <iostream>
using namespace std;
int factorial(int n) {
    cout << "Entering factorial(" << n << ")\n";  // Show state when entering the function
    if (n == 0 || n == 1) {
        cout << "Returning 1 for factorial(" << n << ")\n";  // Base case
        return 1;
    } else {
        int result = n * factorial(n - 1);  // Recursive call
        cout << "Returning " << result << " for factorial(" << n << ")\n";  // Show return state
        return result;
    }
}
int main() {
   int num;
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
