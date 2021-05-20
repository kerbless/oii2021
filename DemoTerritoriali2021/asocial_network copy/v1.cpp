#include <iostream>
#include <vector>
#include <cstdio>
#include <stack> 

using namespace std;

void solve(int t) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    vector<int> F(N, 0); // memorizza qui le risposte
    int provider = 0; 
    stack<int> skipped;
    for (int reciever = 0; reciever < N; reciever++) {
    	cout << reciever << "\n";
        for (int gave = 0; gave < A[reciever]; gave++) { //skips if reciever need is 0, reciever need is stored in A.
            if (provider != reciever) { // you can't follow yourself!
                F[provider] = reciever; //simply the provider follows the reciever
                cout << provider << " followed " << reciever << "\n";
            }
            else {
                cout << "skipped provider " << provider << "\n";
                skipped.push(provider);
                gave--;
            }
            if (provider < N) {
                provider++;
            }
            else if (!skipped.empty()) {
                provider = skipped.top();
                skipped.pop();
                cout << "recovered provider ";
            }   
        }
    }

    
    cout << "Case #" << t << ":";
    for (int i = 0; i < N; i++) {
        cout << " " << F[i];
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        solve(t);
    }
}
