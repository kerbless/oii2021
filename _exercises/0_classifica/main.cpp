#include <bits/stdc++.h>
using namespace std;

bool is_quasipal(string data, int head, int tail) {
    if (tail-head < 2) return true;
    if (data[head] == data[tail] or data[head] == '0' or data[tail] == '0')
        is_quasipal(data, head+1, tail-1);
    else return false;
}

bool are_quasipal(vector<string> data, int row, int col) {
	string column = "";
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; i++) {
            column += data[j][i];
        }
        cout << column;
    }
    return false;
}

void prin(vector<string> data, int row) {
    cout << "\n";
    for (int i = 0; i < row; i++)
        cout << data[i] << "\n";
}

void perm(vector<string> data, int head, int row, int col) {
    if (head == row - 1)
        prin(data, row);
    for (int i = head; i < row; i++) {
        swap(data[head], data[i]);
        perm(data, head+1, row, col);
        swap(data[head], data[i]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
    return 0;
}
