
//https://training.olinfo.it/#/task/piastrelle/statement
#include <iostream>
#include <string>
using namespace std;

void ris(int a[], int N) {
    string small = "[O]", big = "[OOOO]";
    int i;
    for (i = 0; i < N; i++) {
        if (a[i] == 1) cout << small;
        else cout << big;
    }
    cout << endl;
}

int backtrack(int n) {
    if (n == 2) return 1;
    else if (n == 1) return 0;
    return backtrack(n-1);
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, i, j; 
    cin >> N;
    int a[N];
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            a[i] = 0;
            a[j] = 1;
            ris(a, N);
        }
        
    }
    return 0;
}