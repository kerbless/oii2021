#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i, j, N, buy = 0, bestNext, toNext = 0;
    cin >> N;
    int price[N], neededGas[N];
    for (i = 0; i < N; i++) cin >> price[i];
    for (i = 0; i < N; i++) cin >> neededGas[i];

    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) if (price[j] < price[i]) bestNext = j;
        for (j = i; j < bestNext; j++) toNext += neededGas[j];
        buy += toNext*price[i];
    }
    
    cout << buy;
    return 0;
}
