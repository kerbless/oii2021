#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    vector<int> F(N, 0); // memorizza qui le risposte
    for (int i=0; i<N; i++) {
        // F[i] = qualcosa...
    }

    // aggiungi codice...
    
    cout << "Case #" << t << ":";
    for (int i=0; i<N; i++) {
        cout << " " << F[i];
    }
    cout << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        solve(t);
    }
}