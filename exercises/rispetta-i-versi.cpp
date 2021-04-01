#include <iostream>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, i, j, tmp;
    cin >> N; // 2 ≤ N ≤ 100 000.
    char signs[N];
    int result[N], options[N], ;
    for (i = 0; i < N-1; i++) cin >> signs[i]; //potevi anche fare string signs; cin >> signs;
    
    for (j = 0; j < N; j++) {
        options[j] = j+1;
        if (signs[i] = ">") 
    }

    for (j = 0; j < N; j++) {
        options[j] = j+1;
        for (i = 0; i < j; i++) {
            if (i != 0 && (signs[i] = ">" && results[i-1] < results[i]) || (signs[i] = "<" && results[i-1] > results[i])) {
                tmp = results[i];
                results[i] = results[i-1];
                results[i-1] = tmp;
        }
    }
    }

    

    for (i = 0; i < N; i++) cout << results[i];
    return 0;
}
