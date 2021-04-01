#include <iostream>
using namespace std;

int collatz(int); //returns colltz sequence lenght

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int in, out;
    cin >> in; // 2 < in < 1000
    cout << collatz(in);
    return 0;
}

int collatz(int n) {
    int lenght = 1;
    while (n != 1) {
        lenght++;
        n = (n%2) ? (3*n+1) : (n/2); //se c'è un resto esegui l'operazione dopo l'interrogativo, altrimenti esegui l'op. dopo i due punti
    }
    return lenght;
}