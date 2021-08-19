// GOAL: find shortest path from (1) to F (7) of the graph at slide 70
#include <iostream>
#include <limits>
#include "UWG.cpp" // utility functions for Undirected Weighted Graphs made by me
using namespace std;

const unsigned int INF = numeric_limits<unsigned int>::max(); // now "inf" can simulate infinity because it's the max int representable 

void dijkstra (vector<node> graph[], int vertices, int source, int target) {
    T
    for (int i = 0; i < vertices; i++) graph[i]
}

int main() {
    int vertices = 7;
    vector<node> graph[vertices]; //list of vector of nodes (int, int), it's basically and Adj. list
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
    dijkstra(graph, vertices, 1, 7);

    return 0;
}
