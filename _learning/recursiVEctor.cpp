#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vect) {
    vector<int>::iterator it;
    cout << "|";
    for(it = vect.begin(); it < vect.end(); it++) {
        cout << *it << "|";
    }
}

vector<int> recursive(vector<int> vect, int size) {
    if (vect.size() < size) {
        vect.push_back(0);
        return recursive(vect, size);
    }
    else return vect;
}

int main() {
    int size = 4;
    vector<int> vect;
    printVector(recursive(vect, size));
    return 0;
}