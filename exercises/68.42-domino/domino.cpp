//https://training.olinfo.it/#/task/domino/statement
#include <iostream>
using namespace std;

struct card {
    int v[2]; // values
    bool c[2] = {false, false}; // connected
};

void connect(card &a, card &b) { // tries to connect two cards
    int i, j;
    for (i = 0; i < 2; i++) { // cycle trough all combinations
        for (j = 0; j < 2; j++) {
            if (a.c[i] == true || b.c[j] == true) break; // a sides is already connected
            else if (a.v[i] == b.v[j]) { // sides connectable
                a.c[i] = true;
                b.c[j] = true;
                return;
            }
        }
    }
    return;
}

void info(card cards[], int N) { // useful info for debugging
    int i, j;
    for (i = 0; i < N; i++) {
        cout << "Card " << i << " (";
        for (j = 0; j < 2; j++) cout << cards[i].v[j];
        cout << ") is [";
    	for (j = 0; j < 2; j++) cout << cards[i].c[j];
    	cout << "]" << endl;
    }
    return;
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i, j, k, N;
    cin >> N;
    card cards[N];
    for (i = 0; i < N; i++) { 
        for (j = 0; j < 2; j++) {
            cin >> cards[i].v[j]; // getting input
        }
    }

    // the real stuff
    int tot = N;
    for (i = 0; i < N; i++) { 
        for (j = 0; j < N; j++) {
            if (i != j) { // avoid self test
                connect(cards[i], cards[j]); // trying all connections
                // info(cards, N); cout << i << j << " " << tot << endl << endl; // useful info for debugging
            }
        }
        if (cards[i].c[0] == false && cards[i].c[1] == false) tot--;
    }
    cout << tot; 
    return 0;
}