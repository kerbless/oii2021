//https://training.olinfo.it/#/task/abc_esame
/* 10/100
 * tried unsigned ints (maybe add again after time)
 */

#include <bits/stdc++.h>
using namespace std;

void printvect(vector<int> v, int l) {
    for (int i = 0; i < l; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void printmat(vector<vector<int>> mat, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<vector<int>> mat(n, vector<int>(n));
    int maxs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) mat[i][j] = d[i];
            else if (abs(i-j) == 1 or abs(i-j) == n-1) mat[i][j] = max(d[i], d[j]);
            else { 
                if (i <= 2) mat[i][j] = d[i] + d[j];
                else mat[i][j] = d[i] + mat[i-2][j];
            }
            if (mat[i][j] > maxs) maxs = mat[i][j];
        }
    }
    printmat(mat, n, n);
    cout << maxs;
    return 0;
}
