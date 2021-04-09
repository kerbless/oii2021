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
    cout << size << " " << endl;
    
    
    
    
    if (vect.size() < size) {
        if {
            vect.push_back(1);
            size--;
        }
        else vect.push_back(0);
        return backtrack(vect, size);
    }
    else {
        vect.push_back(0); prin(vect);
        return vect; // avoid warning
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