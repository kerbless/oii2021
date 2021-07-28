//https://training.olinfo.it/#/task/alberi/statement
#include <bits/stdc++.h>
using namespace std;


void printVect(vector<int> v) {
    for(vector<int>::iterator it = v.begin(); it < v.end(); it++) {
        cout << *it << " ";
    }
}

struct node {
    node *l;
    int data;
    node *r;
};
vector<node> graph;

void inorder(node* x) {
    if (x == NULL) return;
    inorder(x->l);
    cout << "\nin " << x << " " << x->l << " " << x->r << " <{" << x->data << "}> ";
    inorder(x->r);
}
    
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N; cin >> N;
    vector<int> pre(N), post(N);
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
        node temp;
        temp.r = temp.l = NULL;
        temp.data = pre[i];
        graph.push_back(temp);
        if (i != 0) graph[graph.size()-2].l = &graph.back();
        cout << &graph.back() << " <" << graph.back().data << "> " << graph[graph.size()-2].l << "\n";
    }
    cout << "\n"; printVect(pre);
    for (int i = 0; i < N; i++)
        cin >> post[i];
    cout << "\n"; printVect(post);
    cout << "\n"; inorder(&graph.front());
    return 0;
}
