//https://training.olinfo.it/#/task/sbarramento/statement
#include <iostream>

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, R, row, col;
    std::cin >> N >> R;
    bool map[N][N];
    int col[N];
    for(int i = 0; i < N; i++) {
        int col[N] = 0;
        for(int j = 0; j < N; j++) {
            map[i][j] == false;
        }
    }
    for(int i = 0; i < N; i++) {
        std::cin >> row;
        std::cin >> col;
        map[row][col] == true;
        col[col]++;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (map[i][j] == true) {
            }
        }
    }
    // nord [i − 1, j] (se i > 1), sud [i + 1, j] (se i < N), est [i, j + 1] (se j < N) e ovest [i, j − 1]
    
    return 0;
}
