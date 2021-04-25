//
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    //leggi input
    int nPanini; cin >> nPanini;
    int peso[nPanini];
    for (int i = 0; i < nPanini; i++) cin >> peso[i];

    //individua il sottoproblema da risolvere
    int maxPanini[nPanini] = {0};

    //condizioni iniziali
    maxPanini[0] = 1;

    //riempimento tabella programmazione dinamica
    int max = 1;
    for (int i = 1; i < nPanini; i++) {
        cout << "\n" << "ciclo i " << i << "\n";
        for (int j = i-1; j >= 0; j--) {
            cout << "ciclo j " << j << " conf " << peso[i] << " < " << peso[j] << " && " << maxPanini[i]  << " < " << maxPanini[j] << "\n";
            if (peso[i] < peso[j] && maxPanini[i] < maxPanini[j]) maxPanini[i] = maxPanini[j]; //assengno a max panini di i (panini che posso mangiare mangiando il panino i) il valore di max panini di j solo se posso mangiare il panino j e solo se facendo così non diminuisco il valore max panini di i
        }
        maxPanini[i]++; // aggiungo il panino dello stesso i che vale e varrà nei prossimi test
        if (maxPanini[i] > max) max = maxPanini[i]; //souluzione
        cout << "\t" << "max[i] " << maxPanini[i] << "-- max " << max << "\n";
    }
    cout << max; //output
    return 0;
}
