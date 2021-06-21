#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int ropes; cin >> ropes;
    int parent[ropes], weight[ropes], maxParent = 0, maxWeight = 0, frontIndex = 0;
    for (int i = 0; i < ropes; i++) {
        cin >> parent[i];
        if (parent[i] > maxParent) maxParent = parent[i];
    }
    for (int i = 0; i < ropes; i++) {
        cin >> weight[i];
        if (weight[i] > maxWeight && parent[i] == maxParent) {
            maxWeight = weight[i];
            frontIndex = i;
        }
    }
    
    for (int i = 0; i < ropes; i++) {
        
    }
    
    

    return 0;
}