//https://training.olinfo.it/#/task/poldo/submissions
#include <bits/stdc++.h>
using namespace std;

int solve(int weight[], int current) {
    int ris = 1; // the previous call presuppones that this sandwitch is valid, so + 1
    if (current != 0) { // not in the base case, if current == 0 we return 1 always (the last sandwitch, if valid, is worth 1 all the time)
        int risI, max = 0;
        for (int i = current-1; i > -1; i--) { // calculates every path, if the path is valid adds its value to the ris.
            if (weight[current] < weight[i]) {
                risI = solve(weight, i); //num of valid sandwitches that the I sandwitch brings
                if (risI > max) max = risI;
            }
        }
        ris += max;
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
    
    // solve for every sandwitch and print best
    int risI, max = 1;
    for (int i = 1; i < N; i++) {
        risI = solve(weight, i);
        if (risI > max) max = risI;
    }
    cout << max;
    return 0;
}
