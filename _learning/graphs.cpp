#include <bits/stdc++.h>
using namespace std;

void printvect(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout << " " << v[i];
}

void printdag(vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i+1 << " -> "; printvect(graph[i]); cout << "\n";
    }
}

int main() {
    vector<vector<int>> dag(4); //graph
    dag[0] = {2,3,4};
    dag[1] = {4};
    printdag(dag);
}
