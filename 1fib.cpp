// #include <iostream>
// using namespace std;

// int fibonacci_recursive(int n, int &steps) {
//     steps++; // Increment step count for each call
//     if (n <= 1) {
//         return n;
//     }
//     return fibonacci_recursive(n - 1, steps) + fibonacci_recursive(n - 2, steps);
// }

// int main() {
//     int n = 5; // Change this value to test for different numbers
//     int steps = 0;
//     int result = fibonacci_recursive(n, steps);
    
//     cout << "Fibonacci(" << n << ") = " << result << ", Step count = " << steps << endl;
//     return 0;
// }


//t.c. = o(2^n) 
//s.c. = o(n) - linear due to recursion depth
#include <iostream>
using namespace std;

int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci (Recursive) of " << n << " is: " << fibonacci_recursive(n) << endl;
    return 0;
}


// t.c = o(n) s.c = o(1)
#include<iostream>
using namespace std;

int fibonacci_iterative(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, result;
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacci_iterative(n) << endl;
    return 0;
}


// iterative approach is generally better than the recursive approach



