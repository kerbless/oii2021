// GOAL: find shortest path from (1) to F (7) of the graph at slide 70
#include <iostream>
#include <queue>
#include <limits>
#include "UWG.cpp" // utility functions for Undirected Weighted Graphs made by me
using namespace std;

const int INF = numeric_limits<int>::max(); // now "inf" can simulate infinity because it's the max int representable 

void dijkstra (vector<node> graph[], int vertices, int source, int target) {
    source--; target--; // id to index conversion
    vector<int> dist(vertices, INF); 
    dist[source] = 0;
    for (int i = 0; i < vertices; i++) {
        cout << "\ndistance s -> " << i+1 << " is " << dist[i];
    }
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, source));
    while (!pq.empty()) {
        pair<int, int> looking = pq.top(); // looking = u
        looking.first *= -1;
        pq.pop();
        for (auto& it : graph[looking.second]) { // v = it (u-v)
            if (dist[it.id] = INF) {
                pq.push(make_pair((dist[looking.first] + it.weight) * -1, it.id));
                dist[it.id] = dist[looking] + it.weight;
            }
            else if (dist[looking] + it.weight < dist[it.id]) {
                s.
            }
        }
        break;
    }
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

/*
    for (int i = 0; i < vertices; i++) {
        for (auto& it : graph[i]) {
        }
    }
*/
