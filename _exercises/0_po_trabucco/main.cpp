#include <bits/stdc++.h>
using namespace std;

void printMat(int n, int m, int* mat) {
    cout << "\n";
    for (int i = 0; i < m; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++) {
            cout << mat[i*n+j] << " ";
        }
    }
}

void setRisk(int y, int x, int N, int M, int* mat, int risk) {
    //cout << "\nset_risk " << y << "-" << x << " " << risk;
    if (x > N-1 or x < 0 or y > M-1 or y < 0) {
        //cout << " out_matrix";
        return;
    }
    if (mat[y*N+x] == -1 or mat[y*N+x] > risk) mat[y*N+x] = risk;
    else {
        //cout << " not_new";
        return;
    }
    setRisk(y    , x + 1, N, M, mat, risk+1);
    setRisk(y - 1, x    , N, M, mat, risk+1);
    setRisk(y    , x - 1, N, M, mat, risk+1);
    setRisk(y + 1, x    , N, M, mat, risk+1);
}

int ContaPercorsi(int N, int M, int K, int* X, int* Y) {
    int mat[M*N];
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            mat[i*N+j] = -1;

    for (int i = 0; i < K; i++) { // sentinelle
        setRisk(Y[i], X[i], N, M, mat, 0);
    }

    int startsec = mat[(M-1)*N + N-1];
    if (mat[0] < startsec) startsec = mat[0];

    int tab[M*N];
    int solution = 0;
    int setting;

    while (solution == 0) {
        setting = 1;
        for(int i = 0; i < N; i++) {
            if (mat[i] < startsec) setting = 0;
            tab[i] = setting; // linearizzata!
        }
        setting = 1;
        for(int i = 0; i < M; i++) {
            if (mat[i*N] < startsec) setting = 0;
            tab[i*N] = setting; // linearizzata!
        }
        for(int i = 1; i < N; i++) { 
            for(int j = 1; j < M; j++) {
                if (mat[i*N+j] < startsec) 
                    tab[i*N+j] = 0;
            }
        }
        printMat(N, M, tab);
        printMat(N, M, mat);
        for(int i = 1; i < N; i++) { 
            for(int j = 1; j < M; j++) {
                if (tab[i*N+j] == 0) continue;
                tab[i*N+j] = tab[(i-1)*N+j] + tab[i*N+j-1];
            }
        }printMat(N, M, tab);
    printMat(N, M, mat);
        
        solution = tab[(M-1)*N+N-1];
        startsec--;
        cout << solution;
    }

    // return
    return solution%100000007;
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;
    int X[K], Y[K];
    for (int i = 0; i < K; i++)
        cin >> X[i] >> Y[i];
    ContaPercorsi(N, M, K, X, Y);
    return 0;
}
