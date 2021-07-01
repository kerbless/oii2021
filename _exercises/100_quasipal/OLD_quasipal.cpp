//https://training.olinfo.it/#/task/quasipal/statement
#include <iostream>

bool pali(char word[], int start, int end) {
    if (end-start <= 1) return true; // finished
    if (word[start] == word[end] || word[start] == '0' || word[end] == '0') {
        return true;
        pali(word, start+1, end-1);
    }
    else return false;
}

bool combs(char matrix[][], int start, int end, int target) {
    
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int M, N;
    std::cin >> M >> N; // M numeri N cifre
    char matrix[N][M];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[j][i]; // so j-i is the original order, i-j my order
        }
    }
    //END INPUT---------------------

    //test all rows of this combination
    for (int i = 0; i < N; i++) {
        result += pali(matrix[i], 0, M-1); // start with full size
    }

    //START OUTPUT------------------
    std::cout << result;
    return 0;
}