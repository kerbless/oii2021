// Algoritmo lineare O(n)
#include <iostream>
using namespace std;

unsigned fibonacci (unsigned);

int main() {
    unsigned number, result;

    cout << "Enter integer: ";
    cin >> number;
    result = fibonacci(number);
    cout << endl << "Fibonacci di " << number << " is " << result;
    return 0;
}

unsigned fibonacci(unsigned n) {
    unsigned fib[n];
    fib[1] = fib[2] = 1;
    for (int i = 3; i < n; i++) fib[i] = fib[i-1] + fib[i-2];
    return fib[n];
}