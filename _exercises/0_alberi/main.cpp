//https://training.olinfo.it/#/task/alberi/statement
#include <bits/stdc++.h>
using namespace std;

void printVect(vector<int> v) {
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
}

vector<int> data;
void recursive(vector<int> pre, vector<int> post, int depth, bool left) {
    static int node = 0, last_left = 0;
    if (node == pre.size()) exit(0);
    cout << "\nrecursive called with depth: " << depth;
    cout << "\nvisiting index/node " << node << "->" << pre[node];
    cout << "\nlast_left index/node " << last_left << "->" << post[last_left];
    bool foglia = false; //presuppone not leaf
    if (pre[node] == post[last_left]) {
        foglia = true; //found leaf
        last_left++;
        cout << "\nfound leaf";
    }
    node++;
    if (!foglia) recursive(pre, post, depth+1, true); //left child
    if (left) {
        cout << "\nthis node is left";
        data.push_back(pre[depth]); //save inorder data
        data.push_back(pre[depth-1]); //save inorder data
        cout << "\npushed new data\ndata "; printVect(data);
    }
    cout << "\nrecursive returned, now depth: " << depth;
    cout << "\ncurrent visiting index/node " << node << "->" << pre[node];
    cout << "\ncurrent last_left index/node " << last_left << "->" << post[last_left];
    if (!foglia) recursive(pre, post, depth+1, false); //right child
    cout << "\nrecursive returned, now depth: " << depth;
    cout << "\ncurrent visiting index/node " << node << "->" << pre[node];
    cout << "\ncurrent last_left index/node " << last_left << "->" << post[last_left];
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
    cout << "\npre "; printVect(pre);
    cout << "\npost "; printVect(post);
    recursive(pre, post, 0, true);
    cout << "\n"; printVect(data);
    return 0;
}
