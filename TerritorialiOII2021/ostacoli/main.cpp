#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, L, D;
    cin >> N >> L >> D;

    vector<int> X(N), P(N), S(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> P[i] >> S[i];
    }

    int tempoAttuale = 0;
    int tempoMorto = 0;
    for (int i = 0; i < N; i++) {
        if (i != 0) { // tempo per raggiungere ostacolo successivo
            tempoMorto = S[i] - tempoAttuale;
            if (tempoMorto < 0) break; // ci metti troppo a raggiungere x
        }
        if (i != N-1) { // tempo per raggiungere ostacolo precedente

        }
    }
    int risposta = 42;
    

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("ostacoli_input_1.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}