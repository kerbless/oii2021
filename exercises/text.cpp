//https://training.olinfo.it/#/task/ois_text/statement
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, K, i;
    string words[N];
    cin >> N; // number of words
    cin >> K; // maximum lenght of line
    for (i = 0; i < N; i++) {
        cin >> words[i];
        cout << words[i];
    }    
    

    return 0;
}