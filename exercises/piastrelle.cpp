//https://training.olinfo.it/#/task/piastrelle/statement
#include <iostream>
#include <vector>
using namespace std;

void prin(vector<int> vect) {
    vector<int>::iterator it;
    for(it = vect.begin(); it < vect.end(); it++) {
        if (*it == 0) cout << "[O]";
        else cout << "[OOOO]";
    }
}

vector<int> backtrack(vector<int> vect, int size) {
    int pushing_value = 0;
    if (vect.size() < size) {
        vect.push_back(pushing_value);
        return backtrack(vect, size);
    }
    else return vect;
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N; cin >> N;
    vector<int> vect;
    prin(backtrack(vect, N));
    return 0;
}