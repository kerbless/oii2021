#include <bits/stdc++.h>
using namespace std;

void printMat(int n, int m, int* mat) {
    for (int i = 0; i < m; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++) {
            cout << mat[i*n+j] << " ";
        }
    }
}

void setRisk(int y, int x, int N, int M, int* mat, int risk) {
    cout << "\nset_risk " << y << "-" << x << " " << risk;
    if (x > N-1 or x < 0 or y > M-1 or y < 0) {
        cout << " out_matrix";
        return;
    }
    if (mat[y*N+x] == -1 or mat[y*N+x] > risk) mat[y*N+x] = risk;
    else {
        cout << " not_new";
        return;
    }
    setRisk(y    , x + 1, N, M, mat, risk+1);
    setRisk(y - 1, x    , N, M, mat, risk+1);
    setRisk(y    , x - 1, N, M, mat, risk+1);
    setRisk(y + 1, x    , N, M, mat, risk+1);
}
void allPaths(int y, int x, int N, int M,int* mat, int &valid_paths, int best_security, int path_security) {
    if (mat[y*N+x] < path_security) path_security = mat[y*N+x];
    cout << "\n" << y << " " << x << "  ps" << path_security << "  bs" << best_security << "   vp" << valid_paths;
    if (path_security < best_security) return;

    if (y == M-1 and x == N-1) {
        cout << " end";
        if (path_security == best_security) valid_paths++;
        else if (path_security > best_security) {
            valid_paths = 1;
            best_security = path_security;
            cout << " found better path";
        }
        return;
    }
    if (x < N-1) allPaths(y    , x + 1, N, M, mat, valid_paths, best_security, path_security); //right
    if (y < M-1) allPaths(y + 1, x    , N, M, mat, valid_paths, best_security, path_security); //down
}

int ContaPercorsi(int N, int M, int K, int* X, int* Y) {
    int mat[M*N];
    for(int i =0; i< M; i++)
        for(int j = 0; j < N; j++)
            mat[i*N+j] = -1;
        // sentinelle
    for (int i = 0; i < K; i++) {
        setRisk(Y[i], X[i], N, M, mat, 0);
    }

    int starting_best_security = mat[(M-1)*N + N-1];
    if (mat[0] < starting_best_security) starting_best_security = mat[0];
    int solution = 0;

    allPaths(0, 0, N, M, mat, solution, starting_best_security, mat[0]);
    
    cout << "\nsol: " << solution;

    printMat(N, M, mat);
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
