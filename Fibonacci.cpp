#include <iostream>
#include <chrono>
using namespace std;


int fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}


void fib_non_recursive(int n) {
    int n1 = 0, n2 = 1, n3;
    cout << n1 << " " << n2 << " ";
    for (int i = 2; i < n; ++i) {
        n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
    cout << endl;
}


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "\nFibonacci Sequence (Recursive): ";
    
    for (int i = 0; i < n; i++)
        cout << fib_recursive(i) << " ";
   
    cout << "\n\nFibonacci Sequence (Non-Recursive): ";
    fib_non_recursive(n);
    

  
   
     cout << "Recursive Time Complexity: O(2^n)\n";
     cout << "Recursive Space Complexity: O(n)\n\n";

    
     cout << "Non-Recursive Time Complexity: O(n)\n";
     cout << "Non-Recursive Space Complexity: O(1)\n";

    return 0;
}