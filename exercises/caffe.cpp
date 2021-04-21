//https://training.olinfo.it/#/task/ois_caffe/statement
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int i, a, b, N, presents = 0, coffee = 0; 
    cin >> N;
    map<int, int> time; 
    for(i = 0; i < N; i++) {
        cin >> a >> b;
        time.insert(pair<int,int>(a, b));
    }

    map<int,int>::iterator it, first = time.begin(), last;
    for (last = time.begin(); last != time.end(); last++) {
        presents++;
        cout << "\npres " << presents;
        for(it = first; it != last; it++) {
            cout << "\ndiff " << it->second << " < " << last->first;
            if (it->second < last->first) {
                first++;
                presents--;
                cout << "t";
            }
            else cout << "f";
        }
        coffee += presents;
        cout << "\npres " << presents;
        cout << "\ncoff " << coffee << "\n";
    }

    cout << coffee;
    return 0;
}
