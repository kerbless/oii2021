#include <iostream>
using namespace std;

int collatz(int n); //returns collatz sequence lenght
int pollatzShorter(int n, int max); //returns 1 if pollaz sequence is shorter than max

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int a, b, i, out = 0;
    cin >> a >> b; // a,b | 1 <= a <= b <= 1000
    if (!(1 <= a <= b <= 1000)) return 0;

    for (i = a; i <= b; i++) {
        out += pollatzShorter(i, collatz(i));
    }
    cout << out;
    return 0;
}

int collatz(int n) {
    int lenght = 1;
    while (n != 1) {
        lenght++;
        /*           n odd   n even */
        n = (n%2) ? (3*n+1) : (n/2);
    }
    return lenght;
}

int pollatzShorter(int n, int max) {
    int lenght = 1;
    while (n != 1) {
        lenght++;
        if (lenght > max) return 0;
        if (n%2 == 1) (5*n+1); // ODD
        else (n/2); // EVEN
    }
    return 1;
}