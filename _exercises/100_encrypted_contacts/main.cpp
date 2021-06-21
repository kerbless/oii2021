//https://training.olinfo.it/#/task/ois_ransomware/submissions
#include <bits/stdc++.h>
using namespace std;

int check(string codes[], string x) {
    for (int i = 0; i < 10; i++) {
        if (x == codes[i]) { 
            return i;
        }
    }
    return -1;
}

string stringcheck(string codes[], string x) {
    int start = 0, len, result;
    string send, decrypted;
    for (len = 1; len+start <= x.size(); len++) {
        //cout << start << "-" << len << "_" << x.substr(start, len)<< "\n"; //DEBUG
        result = check(codes, x.substr(start, len));
        if (result != -1) {
            decrypted += to_string(result);
            start += len;
            len = 0;
        }
    }
    return decrypted;
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, tmp;
    cin >> N;
    string encrypted[N];
    for (int i = 0; i < N; i++) {
        cin >> encrypted[i];
    }
    string codes[10];
    for (int i = 0; i < 10; i++) {
        cin >> codes[i];
    }
    for (int i = 0; i < N; i++) {
        cout << stringcheck(codes, encrypted[i]) << "\n";
    }
    
    return 0;
}
