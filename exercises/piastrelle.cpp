//https://training.olinfo.it/#/task/piastrelle/statement
#include <iostream>
#include <vector>
using namespace std;

void prin(vector<int> vect) {
    vector<int>::iterator it;
    for(it = vect.begin(); it < vect.end(); it++) {
        cout << *it << " ";
        // if (*it == 0) cout << "[O]";
        // else cout << "[OOOO]";
    }
    cout << endl;
}

vector<int> backtrack(vector<int> vect, int size) {
    
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N; cin >> N;
    vector<int> vect;
    backtrack(vect, N);
    return 0;
}