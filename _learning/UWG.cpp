// C++ program to represent undirected and weighted graph using STL
#include <vector>
using namespace std;

struct node {     
    int id; //often referred as "v"
    unsigned int weight; //often referred as "w"
};

void addEdge(vector<node> graph[], int parent_id, int child_id, unsigned int child_weight) {
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
