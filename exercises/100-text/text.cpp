//https://training.olinfo.it/#/task/ois_text/statement
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, K, i, len, counter = 0;
    cin >> N; // number of words
    cin >> K; // maximum lenght of line
    string words[N];
    for (i = 0; i < N; i++) {
        cin >> words[i];
    }
    for (i = 0; i < N; i++) {
        len = words[i].length(); // get length of word
        if (len + counter <= K) { // if the lenght + counter is less than K (max)
            cout << words[i] << " "; // N.B. "Spaces at the end of a line will be ignored."
            counter += len + 1;
        }
        else {
            cout << endl; 
            counter = 0;
            i--;
        }
    }

    return 0;
}