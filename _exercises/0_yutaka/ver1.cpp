#include <bits/stdc++.h>
using namespace std;

int taglia(int N, int V[]) {
    unsigned int subComb;
    int comb = 0, subSize = 0;
    for (int i = 0; i < N; i++) {
        subSize++;
        if (V[i] == V[i+1] || i == N-1) {
            if (subSize != 1) {
                subComb = pow(2, subSize-1);
                cout << "\nsub comb with " << i-subSize+1 << "-" << i << " sized " << subSize <<  " = " << subComb << "\n";
                comb += subComb;
            }
            subSize = 0;
        }
    }
    if (comb == 0) comb = 1;
    return comb;
}


int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i, N; cin >> N;
    int V[N]; for (i = 0; i < N; i++) cin >> V[i];
    cout << taglia(N, V);
    return 0;
}
