//https://training.olinfo.it/#/task/alberi/statement
#include <bits/stdc++.h>
using namespace std;

void printVect(vector<int> v) {
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
}

vector<int> data;
void solve(vector<int> pre, vector<int> post) {
    static int visiting = 0; // current node in pre 
    vector<int> left, right; // temporary vectors for recursive calls
    for (int i = 0; i < post.size(); i++) {
        do {
            left.push_back(post[i]);
            i++;
        } while (post[i] != pre[visiting]);
        right.push_back(post[i]);
    }    
    cout << "\n\nleft  "; printVect(left);
    cout << "\nright "; printVect(right);   
    visiting++;
    if (!left.empty()) solve(pre, left);
    if (!right.empty()) solve(pre, right);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; cin >> N;
    vector<int> pre(N), post(N);
    for (int i = 0; i < N; i++)
        cin >> pre[i];
    for (int i = 0; i < N; i++)
        cin >> post[i];
    cout << "\npre  "; printVect(pre);
    cout << "\npost "; printVect(post);
    solve(pre, post);
    return 0;
}
