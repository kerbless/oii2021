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
    multimap<int, int>::iterator it, it2;
    vector<bool> visited(graph.size(), false); // vector used to mark visited nodes (by index)
    vector<int> s; // vector used to store visited nodes in order
    bool found;
    int next;
    s.push_back(0);
    while(true) {
        cout << "\n" << s.back()+1;
        found = false;
        visited[s.back()] = true; // using the node as an index to mark it visited in the vector
        for (it = graph[s.back()].begin(); it != graph[s.back()].end(); it++) {
            // iterating through all the neighbours of current node
            if (visited[it->second-1]) { // if neighboud VISITED
                if (it->second-1 != s.end()[-2]) { //and neighbour not parent (non-penultimate) -> cycle found
                    cout << " cycle " << it->second << "->";// << s.back()+1 << it->second;
                    // here I need to iterate trough all neighbour of the neighbour I found, using recursion? or using something to find the starting node again from any path that's already visited. (in the first case something like 1235, 125, 214, 234)
                }
            }
            else { //if neighbour UNVISITED
                if (!found) {
                    next = it->second-1;
                    found = true;
                }
            }
        }
        if (found) s.push_back(next);
        else s.pop_back();
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
