#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

using namespace std;

void solve(int t) {
    int N, max = 0, risposta = 0;
    cin >> N;

    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
        max = A[i];
        if(max < B[i]) max = B[i];
        if(max < C[i]) max = C[i];
        risposta += max;
    }

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    freopen("pile_input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}