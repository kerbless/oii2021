//https://training.olinfo.it/#/task/mappa/statement
#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i, j, steps = 1, N; cin >> N;
    int right = 0, down = 0, diagonal = 0;
    char t[N][N]; // "+" are deadly "*" are okay
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> t[i][j];
        }
    }
    

    // for (i = 0; i < N; i++) {
    //     for (j = 0; j < N; j++) {
    //         if (t[i+1][j] == '*') right = 1; // right
    //         else if (t[i][j+1] == '*') down = 1; // down
    //         else if (t[i+1][j+1] == '*') diagonal = 1; // diagonal
    //         else t[i][j] = '+';
    //     }
    // }
    // for (i = 0; i < N; i++) {
    //     for (j = 0; j < N; j++) {
    //         cout << t[i][j]; 
    //     }
    //     cout<<endl;
    // }
    cout << steps;
    return 0;
}