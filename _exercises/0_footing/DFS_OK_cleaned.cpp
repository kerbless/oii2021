//https://training.olinfo.it/#/task/footing/statement
#include <bits/stdc++.h>
using namespace std;

/*
1`2  2`4  5`5  
1`1  2`3  4`6  6`5  
1`5  2`2  3`6  7`4  
2`5  2`1  7`3  
1`3  2`4  5`1  6`2  
3`3  4`2  
*/

void printgraph(vector<multimap<int, int> > graph) {
    for (int i = 0; i < graph.size(); i++) {
        for (multimap<int, int>::iterator it = graph[i].begin(); it != graph[i].end(); it++) {
            cout << (*it).first << "`" << it->second << "  ";
        }
        cout << "\n";
    }
}

void DFS(vector<multimap<int, int> > graph) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    bool allUnvisited;
    s.push(0);
    while(true) {
        cout << s.top()+1 << " ";
        allUnvisited = true;
        visited[s.top()] = true;
        for (multimap<int, int>::iterator it = graph[s.top()].begin(); it != graph[s.top()].end(); it++)
            if (!visited[(*it).second-1]) {
                s.push(it->second-1);
                allUnvisited = false;
                break;
            }
        if (allUnvisited) s.pop();
        if (all_of(visited.begin(), visited.end(), [](bool i){return i;}) or s.empty()) break;
    };
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
    int n_nodes, n_links;
    cin >> n_nodes >> n_links;
    vector<multimap<int, int> > graph(n_nodes); // vector of nodes, every node has a multimap of links (weight -> target)
    int node1, node2, weight;
    for (int i = 0; i < n_links; i++) {
        cin >> node1 >> node2 >> weight;
        graph[node1-1].insert(make_pair(weight, node2));
        graph[node2-1].insert(make_pair(weight, node1));
    }
    printgraph(graph);
    DFS(graph);
    return 0;
}
