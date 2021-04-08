#include <iostream>
#include <map>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i, N, weight, parents = 0, time = 0; 
    cin >> N;
    int parent[N], times[N];
    multimap<int, int> ropes;
    for (i = 0; i < N; i++) {
        cin >> parent[i];
        parents += parent[i];
    }
    for (i = 0; i < N; i++) cin >> times[i];

    for (i = 0; i < N; i++) {
        weight = times[i] + (parent[i]*1000);
        ropes.insert(pair<int, int>(weight, times[i]));
    }

    //for(auto elem : ropes) cout << elem.first << " " << elem.second << endl;
    multimap<int, int>::iterator it, 
    begin = ropes.begin(), 
    end = prev(ropes.end(), parents+1);

    cout << distance(begin, end) << endl;
    for(it = begin; it != end; it++) time += (*it).second;
    cout << time;
    
    return 0;
}