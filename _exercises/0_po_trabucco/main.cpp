// https://training.olinfo.it/#/task/po_trabucco/statement
#include <bits/stdc++.h>
using namespace std;

/* 
  TODO
  Increase size type for ultra big matrixes (long int)
  Optimize solution cycles with lighter 0 initializer
  Optimize memory removing unused data (1 tab?)
  Optimize soludion cycles ?
*/


/* 
   we used linearized matrices as it's simpler to pass them to functions
   an alternative would be using vector of vectors (STL)
*/

/* 
   matrixes have N COLUMNS and M ROWS (N -> x)
*/

// simple matrix printer function used for debugging
void printMat(int n, int m, int* mat) {
    cout << "\n";
    for (int i = 0; i < m; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++) {
            cout << mat[i*n+j] << " ";
        }
    }
}

// function that sets security for each cell using recursive approach
// TODO: optimize by reducing multiple passes on same cell (is it possible?)
void setRisk(int y, int x, int N, int M, int* mat, int risk) {
    if (x > N-1 or x < 0 or y > M-1 or y < 0) return;
    if (mat[y*N+x] == -1 or mat[y*N+x] > risk) mat[y*N+x] = risk;
    else return;
	//cout << "\nsetrisk " << y << "-" << x << " " << risk;
    setRisk(y    , x + 1, N, M, mat, risk+1);
    setRisk(y - 1, x    , N, M, mat, risk+1);
    setRisk(y    , x - 1, N, M, mat, risk+1);
    setRisk(y + 1, x    , N, M, mat, risk+1);
}

// main function that counts every shortest most secure path
int ContaPercorsi(int N, int M, int K, int* X, int* Y) {

	// create and initalize mat to -1
    int mat[M*N];
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            mat[i*N+j] = -1;

	// set cell securities based on sentries positions
    for (int i = 0; i < K; i++) {
        setRisk(Y[i], X[i], N, M, mat, 0);
    }
	printMat(N, M, mat);	

	// calculate best case starting security (worst of starting/ending cells)
    int startsec = mat[(M-1)*N + N-1];
    if (mat[0] < startsec) startsec = mat[0];
	cout << "\nbest case startsec: " << startsec;

	// create dynamic programming table (matrix) and needed variables
    int tab[M*N];
    int solution = 0;
    int setting;

	// calculating paths decrementing startsec until solution > 0
    while (solution <= 0) {
		
		// initializing borders of the d.p. table with 1s and 0s using startec
        setting = 1;
        for(int i = 0; i < N; i++) {
            if (mat[i] < startsec) setting = 0;
            tab[i] = setting;
        }
        setting = 1;
        for(int i = 0; i < M; i++) {
            if (mat[i*N] < startsec) setting = 0;
            tab[i*N] = setting;
        }
		
		// initializing the rest d.p. table 0s using startsec
        // TODO: maybe we could do this following setRisk (starting from the zeros) to avoid exploring the whole matrix?
		cout << "\nstartsec: " << startsec;
        for(int i = 1; i < M; i++) { 
            for(int j = 1; j < N; j++) {
                if (mat[i*N+j] < startsec) {
                    tab[i*N+j] = 0;
                }
                else tab[i*N+j] = 9; // filler, just for debugging
            }
        }
		printMat(N, M, tab);

		// building the d.p. table using the Rows of the Pascal Triangle
        for(int i = 1; i < M; i++) { 
            for(int j = 1; j < N; j++) {
                if (tab[i*N+j] == 0) continue;
                tab[i*N+j] = tab[(i-1)*N+j] + tab[i*N+j-1];
            }
        }
        
		// saving solution and preparing startsec for the eventual next cycle
        solution = tab[(M-1)*N+N-1];
        startsec--;
        printMat(N, M, tab);
        cout << "\nsol: " << solution;
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
