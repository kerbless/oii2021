#include <bits/stdc++.h>
using namespace std;

int ContaPercorsi(int, int, int, int*, int*);
void setRisk(int y, int x, int N, int M, vector<vector<int> > &mat, int risk) {
    //cout << "\nset_risk " << y << "-" << x << " " << risk;
    if (x > N-1 or x < 0 or y > M-1 or y < 0) {
        //cout << " out_matrix"; 
        return;
    }
    if (mat[y][x] == -1 or mat[y][x] > risk) mat[y][x] = risk;
    else {
        //cout << " not_new";
        return;
    }
    setRisk(y    , x + 1, N, M, mat, risk+1);
    setRisk(y - 1, x    , N, M, mat, risk+1);
    setRisk(y    , x - 1, N, M, mat, risk+1);
    setRisk(y + 1, x    , N, M, mat, risk+1);
}
void allPaths(int y, int x, int N, int M, vector<vector<int> > mat, int &valid_paths, int best_security, int path_security) {
    if (mat[y][x] < path_security) path_security = mat[y][x];
    cout << "\n" << y << " " << x << "  ps" << path_security << "  bs" << best_security << "   vp" << valid_paths; 
    if (path_security < best_security) return;

    if (y == M-1 and x == N-1) {
        if (path_security == best_security) valid_paths++;
        else if (path_security > best_security) {
            valid_paths = 1;
            best_security = path_security;
        }
        return;
    }
    if (x < N-1) allPaths(y    , x + 1, N, M, mat, valid_paths, best_security, path_security); //right
    if (y < M-1) allPaths(y + 1, x    , N, M, mat, valid_paths, best_security, path_security); //down  
}


int main() {
    freopen("input0.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;
    int X[K], Y[K];
    for (int i = 0; i < K; i++)
        cin >> X[i] >> Y[i];
    ContaPercorsi(N, M, K, X, Y);
    return 0;
}

int ContaPercorsi(int N, int M, int K, int* X, int* Y) {
    vector<vector<int> > mat(M, vector<int>(N, -1));
    
    // sentinelle 
    for (int i = 0; i < K; i++) {
        setRisk(Y[i], X[i], N, M, mat, 0);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

        }
    }

    // print
    for (int i = 0; i < M; i++) {
        cout << "\n";
        for (int j = 0; j < N; j++) {
            cout << mat[i][j] << " ";
        }
    }
    int starting_best_security = mat[M-1][N-1];
    if (mat[0][0] < starting_best_security) starting_best_security = mat[0][0];
    int solution = 0;
    allPaths(0, 0, N, M, mat, solution, starting_best_security, mat[0][0]); 
    cout << endl << solution << endl;
    // return
    return solution%100000007;
}
