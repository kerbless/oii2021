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

vector<node> addnode(vector<node> graph, int data, bool left) {
    node adding;
    adding.l = NULL;
    adding.r = NULL;
    adding.data = data;
    if (graph.empty()) graph.push_back(adding);
    else {
        graph.push_back(adding);
        if (left) graph[graph.size()-2].l = &graph.back(); //last element inside the vector gets address
        else graph[graph.size()-2].r = &graph.back(); //right side
    }
    return graph;
}

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
    vector<node> graph;
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
        node adding;
        adding.l = adding.r = NULL;
        adding.data = pre[i];
        graph.push_back(adding);
        if (!graph.empty()) {
            graph[graph.size()-2].l = &graph.back(); //last element inside the vector gets address
        }
    }
    for (int i = 0; i < N; i++)
        cin >> post[i];
    cout << "\n";
    printVect(pre);
    cout << "\n";
    printVect(post);
    cout << "\n";
    for (int i = 0; i < graph.size(); i++) {
        cout << graph[i].data << " " << &graph[i] << " " << graph[i].l << " " << graph[i].r << "\n";
    }
    inorder(&graph[graph.size()-5]);
    return 0;
}
