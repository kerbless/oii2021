#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    unsigned int i, j, chambers, set, tmp, ris = 0;
    cin >> chambers >> set;
    unsigned int height[chambers], jmp[chambers-1];
    for (i = 0; i < chambers; i++) {
        cin >> height[i];
    }
    for (i = 0; i < chambers; i++) { // sort
        for (j = i+1; j < chambers; j++) {
            if (height[i] < height[j]) {
                tmp = height[i];
                height[i] = height[j];
                height[j] = tmp;
            }
        }
    }
    for (i = 1; i < chambers; i++) {
        jmp[i] = height[i-1] - height[i];
    }
    for (i = 0; i < chambers; i++) { // sort
        for (j = i+1; j < chambers; j++) {
            if (jmp[i] < jmp[j]) {
                tmp = jmp[i];
                jmp[i] = jmp[j];
                jmp[j] = tmp;
            }
        }
    }
    for (i = chambers-1; i >= chambers-set; i--) {
        ris += jmp[i];
    }

    for (i = 0; i < chambers; i++) {
        cout << height[i] << " ";
    }
    cout << endl;
    for (i = 0; i < chambers; i++) {
        cout << jmp[i] << " ";
    }

    cout << endl << ris;
    
    return 0;
}

void sort(unsigned int x[]) {
    
}