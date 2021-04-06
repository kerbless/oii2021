#include <iostream>
using namespace std; // 4 6

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    long unsigned int N, gasToBuy, spent = 0, station = 0, bestNext;
    int i;
    cin >> N; // gets number of stations
    long unsigned int price[N], gasToNext[N];
    for (i = 0; i < N; i++) cin >> price[i]; // gets prices
    for (i = 0; i < N; i++) cin >> gasToNext[i]; // gest gasToNext values
    while (station < N) {
        bestNext = station; // assumes that this station is the best one
        for (i = station; i < N; i++) { // finds best next station // +1 breaks single station test?s
            if (price[i] < price[station]) {
                bestNext = i;
                break; // stops looking for next best // "i = N; works too"
            }
        }
        if (bestNext == station) bestNext = N;// if this is the best station ever, buy all. (0-N gas, the last station "N" is imaginary, is the finish point)
        gasToBuy = 0;
        i = station;
        for (i = station; i < bestNext; i++) gasToBuy += gasToNext[i]; // calculates needed gas to bestNext
        spent += gasToBuy*price[station]; // calculates spent money to get the gasToBuy

        cout << "station = " << station << endl;
        cout << "bestNext = " << bestNext << endl;
        cout << "gasToNext = " << gasToNext[station] << endl;
        cout << "gasToBuy = " << gasToBuy << endl;
        cout << "price = " << price[station] << endl;
        cout << "spent = " << spent << endl << endl;

        station = bestNext; // jumps to next best station
    }
    cout << spent; // returns total spent
    return 0;
}
