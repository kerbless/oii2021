#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pesci_input_1.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        unsigned fishes, groupSize;
        cin >> fishes >> groupSize;
        unsigned solution = 0;
        while (fishes > 0) {
            solution += fishes;
            fishes = fishes / groupSize;
        }
        


        cout << "Case #" << t+1 << ": " << solution << "\n";
    }
    return 0;
}
