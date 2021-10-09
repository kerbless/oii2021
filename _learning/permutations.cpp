#include <bits/stdc++.h>
using namespace std;


void print1d(vector<int> x, int l);
void print2d(vector< vector<int> > x, int row, int col);
vector<int> permutations(vector<int> x, int l);


int main() {
    vector<int> v{1, 2, 3};
    permutations(v, v.size(), 0);
}

void print1d(vector<int> x, int l) {
    cout << "\n";
    for (int i = 0; i < l; i++)
        cout << x[i] << " ";
}

void print2d(vector< vector<int> > x, int row, int col) {
    cout << "\n";
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) { 
            cout << x[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<int> permutations(vector<int> x, int l, int fx) {
    for (int i = fx; i < l; i++) {
        int head = x[i];
        r.erase(r.begin()+i);
        r = permutations(r, l-1);
        r.insert(r.begin(), head);
    }

    vector<int> r;
    if (l == 1) return x;
    for (int i = 0; i < l; i++) {
        // skip first iteration as it does nothing?
        r = x;
        int head = x[i];
        r.erase(r.begin()+i);
        r = permutations(r, l-1);
        r.insert(r.begin(), head);
    }
    // if (r.size() == x.size()) print1d(r, r.size());
    return r;
 
void permutations(string str, int i, int n) {
    // base condition
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }
 
    // process each character of the remaining string
    for (int j = i; j < n; j++)
    {
        // swap character at index `i` with the current character
        swap(str[i], str[j]);        // STL `swap()` used
 
        // recur for substring `str[i+1, n-1]`
        permutations(str, i + 1, n);
 
        // backtrack (restore the string to its original state)
        swap(str[i], str[j]);
    }
}
 
int main()
{
    string str = "ABC";
 
    permutations(str, 0, str.length());
 
    return 0;
}