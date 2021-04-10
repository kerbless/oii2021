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
    cout << endl;
}

void backtrack(vector<int> vect, int size) {
    if (vect.size() == size) {
        prin(vect);
        return;
    } 
    else if (vect.size() < size) {
        vect.push_back(0);
        backtrack(vect, size);
        vect.pop_back();
        vect.push_back(1);
        backtrack(vect, --size);
        return;
    }
     
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N; cin >> N;
    vector<int> vect;
    backtrack(vect, N);
    return 0;
}