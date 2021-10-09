#include <bits/stdc++.h>
using namespace std;


void printVect(vector<int> x, int l);
void printMat(vector< vector<int> > x, int row, int col);
vector< vector<int>> initMatrix(int row, int col);

int main() {
    int row = 4;
    int col = 26;
    vector<vector<int>> mat = initMatrix(row, col);
    printMat(mat, row, col);
}

vector< vector<int>> initMatrix(int row, int col) {
    /* Uglier option
            vector<vector<int>> mat;
            mat.resize(rows);
            for(int i = 0; i < rows; i++)
                mat[i].resize(columns);
            return mat;
    */
    return vector<vector<int>> (row, vector<int>(col, 0));
}

void printVect(vector<int> x, int l) {
    cout << "\n";
    for (int i = 0; i < l; i++)
        cout << x[i] << " ";
}

void printMat(vector< vector<int> > x, int row, int col) {
    cout << "\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) { 
            cout << x[i][j] << " ";
        }
        cout << "\n";
    }
}