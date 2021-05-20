#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N; cin >> N;
    long temp, row_tot;
    priority_queue<pair<long, int>> scoreboard;

    for(int i = 1; i < N+1; i++) { // requested indexes 1->N
        row_tot = 1; // compensate the -1;
        for(int j = 0; j < N+1; j++) {
            cin >> temp;
            row_tot += temp;
        }
        scoreboard.push(make_pair(row_tot, i));
        cout << scoreboard.top().second << "\n";
    }

    return 0;
}
