//https://training.olinfo.it/#/task/quasipal/statement
#include <bits/stdc++.h>
using namespace std;

bool is_quasipal(vector<char> v, int l) {
    l--; //lenght to last element index
    for (int i = 0; i < l; i++) {
        //cout << v[i] << " " << v[l] << "\n";
        if (not (v[i] == v[l] or v[i] == '0' or v[l] == '0')) return false;
        l--;
    }
    return true;
}

void printvect(vector<char> v, int l) {
    for (int i = 0; i < l; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void printmat(vector<vector<char>> mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

bool are_quasipal(vector<vector<char>> mat, int m, int n) {
    vector<char> send(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            send[j] = mat[j][i];
        //cout << "check "; printvect(send, m); cout << " is " << is_quasipal(send, m) << "\n";
        if (not is_quasipal(send, m)) return false;
    }
    return true;
}

void perm(vector<vector<char>> mat, int m, int n, int start_index) {
    //cout << m << "," << start_index << "\n";
    if (start_index == m)
        if (are_quasipal(mat, m, n)) {
            printmat(mat, m, n);
            exit(0);
        }
    for (int i = start_index; i < m; i++) {
        swap(mat[start_index], mat[i]);
        perm(mat, m, n, start_index+1);
        swap(mat[start_index], mat[i]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int m, n;
    cin >> m >> n; 
    vector<vector<char>> mat(m, vector<char>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    perm(mat, m, n, 0);
    return 0;
}
