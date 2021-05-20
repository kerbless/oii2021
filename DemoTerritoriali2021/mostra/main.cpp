#include <bits/stdc++>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

int solve() {
    int N, M;
    cin >> N >> M;

    int risposta = 0;  // memorizza qui la risposta
    vector<int> V(N), G(M);
    for (int i=0; i<N; i++) {
        cin >> V[i];
    }
    for (int i=0; i<M; i++) {
        cin >> G[i];
    }

    int i = 0;
    vector<int> money;
    while(true) {
        if (i < M && i < N) {
            if (V[i] < G[i]) {
                //
            }
            else {
                
            }
        }
        i++;
    }

    // aggiungi codice...

    return risposta;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}