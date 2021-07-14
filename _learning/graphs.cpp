#include <bits/stdc++.h>
using namespace std;

void printvect(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout << " " << v[i];
}

void printdug(vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); i++) {
        cout << i+1 << " -> "; printvect(graph[i]); cout << "\n";
    }
    cout << "\n";
}

int main() {
    vector<vector<int>> dag(4); //graph
    dag[0] = {2,3,4};
    dag[1] = {4};
    vector<vector<int>> dcg(7); //graph (using 0 padding indexes 1+)
    dcg[1] = {2};
    dcg[2] = {3};
    dcg[3] = {4};
    dcg[4] = {2, 6};
    dcg[5] = {3};
    printdug(dag);
    printdug(dcg);
    vector<pair<pair<int, int>, int>> ucwg(6);
    ucwg[0] = pair<pair<int, int>, int>(pair<int, int>(1,2), 1);
    for (int i = 0; i < ucwg.size(); i++) {
        cout << i << " = " << 
    }
    

}
