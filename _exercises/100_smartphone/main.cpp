#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    unsigned int N, in, last = 0;
    unsigned long int tot = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> in;
        if (in > last) {
            tot += in;
            last = in;
        }
    }
    cout << tot;
    return 0;
}
