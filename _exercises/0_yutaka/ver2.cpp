#include <bits/stdc++.h>
using namespace std;

int taglia(int N, int V[], int cuts, int lastcut, int candidate) {
    //debug
    cout << "\n";
    for(int i = lastcut; i < candidate; i++) {
        cout << V[i] << " ";
    }
    cout << " " << V[candidate];

    bool mustCut = false;
    for (int i = candidate-1; i > lastcut-1; i--) {
        cout << "\nchecking " << V[i] << "=" << V[candidate];
        if (V[i] == V[candidate]) {
            mustCut = true;
            break;
        }
    }
    if (candidate == N) return cuts;
    cuts += taglia(N, V, ++cuts, ++lastcut, ++candidate);
    if (mustCut == false) cuts += taglia(N, V, cuts, lastcut, ++candidate);
    return cuts;
}

int main() {
    freopen("input.txt", "r", stdin);
    int i, N; cin >> N; 
    int V[N]; for (i = 0; i < N; i++) cin >> V[i];
    cout << taglia(N, V, 0, 0, 1);
    return 0;
}
