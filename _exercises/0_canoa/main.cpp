#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, K, f, p, v;
    cin >> N >> K;
    multimap<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> f >> p;
        v = f/p;
        m.insert(pair<int, int>(v,i+1));
    }
    for (multimap<int, int>::iterator it = m.begin(); it != m.end(); it++)
        cout << (*it).first << " " << (*it).second << "\n";
    return 0;
}
