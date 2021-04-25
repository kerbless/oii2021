#include <bits/stdc++.h>
using namespace std;

int solve(int weight[], int current) {
    cout << current << "________solve call\n";
    cout << current << "called with sandwitch " << current << " weighted " << weight[current] << "\n";
    int ris = 1; // the previous call presuppones that this sandwitch is valid, so + 1
    if (current != 0) { // not in the base case, if current == 0 we return 1 always (the last sandwitch, if valid, is worth 1 all the time)
        int risI, max = 0;
        for (int i = current-1; i > -1; i--) { // calculates every path, if the path is valid adds its value to the ris.
            if (weight[current] < weight[i]) {
                cout << current << "calling solve for sandwitch " << i << " weighted " << weight[i] << "\n";
                risI = solve(weight, i); //num of valid sandwitches that the I sandwitch brings
                if (risI > max) max = risI;
                cout << current << "resulted in risI " << risI << "\n";
                cout << current << "now max is " << max << "\n";
            }
            else {
                cout << current << "solve uncalled for " << i << " weighted " << weight[i] << "\n";
            }
        }
        ris += max;
    }
    else {
        cout << current << "current 0" << "\n";
    }
    return ris;
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N; 
    cin >> N;
    int weight[N], qt[N] = {1};
    for (int i = 0; i < N; i++) cin >> weight[i];
    int res = solve(weight, N-1);
    cout << "res " << res;
    
    // int risI, max = 1;
    // for (int i = 1; i < N; i++) {
    //     risI = solve(weight, i);
    //     if (risI > max) max = risI;
    // }
    // cout << current << solve(weight, N);
    return 0;
}
