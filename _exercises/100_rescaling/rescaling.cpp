//https://training.olinfo.it/#/task/ois_rescaling/statement
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i, N, max = 1;
    cin >> N;
    unsigned S[N], sub[N];
    for (int i = 0; i < N; i++) {
        cin >> S[i]; 
        sub[i] = 1;
    }
    
    for (int i = 1; i < N; i++) { //every number
    //cout << "\ni" << i; //DEBUG
        for (int j = 0; j < i; j++) {
            //cout << "\nj" << j; //DEBUG
            if (sub[j]+1 > sub[i]) {
                if (S[i] < S[j] || S[i] % S[j] == 0) { //i number is valid for the subsequence
                    sub[i] = sub[j]+1;
                    //cout << "\nsub[i]: " << sub[i]; //DEBUG
                }
                //else cout << "\nNotValid"; //DEBUG
            }
            //else cout << "\nNotBetter"; //DEBUG
            if (sub[i] > max) max = sub[i];
            //cout << "\nMax:" << max; //DEBUG
        }
    }

    cout << N-max;
    return 0;
}
