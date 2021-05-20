//https://training.olinfo.it/#/task/lwf/statement
#include <bits/stdc++.h>
using namespace std;

void prin(vector<int> v) {
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N; cin >> N; // number to encode
    vector<int> solution;
    vector<int> fib = {1,1};
    int fibsum = 2;

    //calculate fibonacci sequence necessary
    for (int i = 2; fibsum < N; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        fibsum += fib[i];
    }
    
    //subtract method
    while(true) {
        if (N - fib.back() > 0) {
            solution.insert(solution.begin(), 1);
            N -= fib.back();
        }
        else if (N - fib.back() == 0) {
            solution.insert(solution.begin(), 1);
            fib.pop_back();
            for (int i = 0; i < fib.size(); i++) solution.insert(solution.begin(), 0);
            break;
        }
        else solution.insert(solution.begin(), 0);
        fib.pop_back();
    }

    //end
    prin(solution);
    return 0;
}
