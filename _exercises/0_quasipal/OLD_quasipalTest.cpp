//https://training.olinfo.it/#/task/quasipal/statement
#include <iostream>

void pali(char word[], int start, int end) {
    
    //DEBUG
    std::cout << "pali (";
    for (int i = start; i <= end; i++) {
        std::cout << word[i];
    }
    std::cout << ")" << std::endl;

    if (end-start <= 0) return; // finished
    else if (word[start] == word[end] || word[start] == '0' || word[end] == '0') {
        std::cout << "OK AT " << start << end << std::endl;
    }
    else std::cout << "BAD AT " << start << end << std::endl;
    pali(word, start+1, end-1);
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

    for (int i = 0; i < N; i++) {

        //DEBUG
        std::cout << "\nCalling pali with matrix " << i << " and s-e 0-" << M-1 << std::endl;
        
        pali(matrix[i], 0, M-1); // start with full size
    }

    //START OUTPUT------------------
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[j][i];
        }
        std::cout << std::endl;
    }
    return 0;
}
