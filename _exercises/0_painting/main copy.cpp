#include <bits/stdc++.h>
using namespace std;
/*
a = column start
b = column end
c = row start
d = row end
*/

void subsec(string in[], int a, int b, int c, int d, string& out[]) {
    for(int i = a; i < b; i++)
        for(int j = c; j < d; j++)
            out[i][j] = in[i][j];

}

bool isEmpty(string in[], int l) {
    for(int i = 0; i < l; i++)
        for(int j = 0; j < l; j++)
            if (in[i][j] == '*')
                return false;
    return true;
}

void applyModel(string model[], string& out[]) {

}

void solve(string data[], int len) {
    string sub[len/2][len/2];
    subsec(data, 0, len/2, 0, len/2, sub); // top left
    subsec(data, 0, len/2, len/2, len, sub); // top right
    subsec(data, len/2, len, 0, len/2, sub); // bottom left
    subsec(data, len/2, len, len/2, len, sub); // bottom right
}



int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    // getting sizes
    int N, K; cin >> N; cin >> K;

    // get model
    vector<string> model(N);
    for(int i = 0; i < N; i++)
        cin >> model[i];

    // calculate size of result matrix
    int NK = pow(N, K);

    // initialize result matrix
    cout << "\n";
    vector<string> result(NK);
    for(int i = 0; i < NK; i++)
        for(int j = 0; j < NK; j++)
            result[i][j] = '.';

//------------------------------------
    // invoke solve function
    solve(result, NK);

    return 0;
}
