// C++ program to represent undirected and weighted graph using STL
#include <iostream>
#include <vector>
using namespace std;

struct node {     
    int id; //often referred as "v"
    int weight; //often referred as "w"
};

void addEdge(vector<node> graph[], int parent_id, int child_id, int child_weight) {
    node child;
    child.id = child_id; // id to index conversion
    child.weight = child_weight;
    graph[parent_id-1].push_back(child);
}

void printGraph(vector<node> graph[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        cout << "\nnode [" << i+1 << "] edges:"; // index to id conversion
        for (auto& child : graph[i])
            cout << " " << child.id << "(" << child.weight << ")";
    }
}
 
int main()
{
    int vertices = 7;
    vector<node> graph[vertices]; //list of vector of nodes (int, int)
    addEdge(graph, 1, 2, 7);
    addEdge(graph, 1, 3, 14);
    addEdge(graph, 1, 4, 30);
    addEdge(graph, 2, 3, 6);
    addEdge(graph, 4, 3, 10);
    addEdge(graph, 3, 5, 1);
    addEdge(graph, 5, 6, 6);
    addEdge(graph, 5, 7, 9);
    addEdge(graph, 6, 7, 4);
    printGraph(graph, vertices);
    return 0;
}

/* -- REMEMBER --
 * Often those mean the same:
 *  parent_id = u
 *  child_id = v
 *  child_weight = w
 * 
 * And:
 *  for (auto& parent : graph)
 * could be seen as:
 *  for (auto child = graph[parent].begin(); child != graph[parent].end(); child++)
 * in C++11 and newer
 *
 */
