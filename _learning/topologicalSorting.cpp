#include <bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int> > m) {
    for (int i = 0; i < m.size(); i++) {
        cout << i+1 << " -> ";
        for (int j = 0; j < m[i].size(); j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

void printVect(vector<bool> v) { 
    cout << "\n";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
}


void printVect(vector<int> v) { 
    cout << "\n";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
}

vector<vector<int> > outToIn(vector<vector<int> > outgoing) {
    vector<vector<int> > incoming(outgoing.size());
    for (int i = 0; i < outgoing.size(); i++) {
        for (int j = 0; j < outgoing[i].size(); j++) {
            incoming[outgoing[i][j]-1].push_back(i+1);
        }
    }
    return incoming;
}

vector<vector<int> > outToMat(vector<vector<int> > outgoing) {
    vector<vector<int> > matrix(outgoing.size(), vector<int>(outgoing.size(), 0));
    for (int i = 0; i < outgoing.size(); i++) {
        for (int j = 0; j < outgoing[i].size(); j++) {
            matrix[i][outgoing[i][j]-1] = 1;
        }
    }
    return matrix;
}

bool isAllZero(vector<int> a) {
    for (auto it = a.begin(); it != a.end(); it++) {
        if (*it == 1) return false;    
    }
    return true;
}

inline void setZero(vector<vector<int>> &a, int node) {
    cout << "\ncalled zetZero with node " << node;
    for (auto it = a.begin(); it != a.end(); it++)
        (*it)[node-1] = 0;
}

int main() {
    vector<int> topologic;
    vector<vector<int> > outgoing = {
        {2},
        {3, 4, 5},
        {4},
        {},
        {4},
        {},
        };
    printMat(outgoing);
    vector<vector<int> > incoming = outToIn(outgoing);
    cout << "\n"; printMat(incoming);
    vector<vector<int> > matrix = outToMat(incoming);
    cout << "\n"; printMat(matrix);
    vector<bool> visited(outgoing.size(), false);
    stack<int> free;
    int node = 1;
    for (auto it = matrix.begin(); it != matrix.end(); it++) {
        if (isAllZero(*it) and !visited[node-1]) {
            free.push(node);
            visited[node-1] = true;
        }
        node++;
    }
    
    while(!free.empty()) {
        printVect(visited);
        topologic.push_back(free.top());
        setZero(matrix, free.top());
        cout << "\n"; printMat(matrix);
        free.pop();

        node = 1;
        for (auto it = matrix.begin(); it != matrix.end(); it++) {
            if (isAllZero(*it) and !visited[node-1]) {
                free.push(node);
                visited[node-1] = true;
            }
            node++;
        }
    }
    printVect(topologic);
}
