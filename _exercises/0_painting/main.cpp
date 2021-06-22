#include <bits/stdc++.h>
using namespace std;

vector<string> applyModel(vector<string> model, vector<string> in) {

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

    // print result matrix
    for(int i = 0; i < NK; i++) {
        for(int j = 0; j < NK; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
