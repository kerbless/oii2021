#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, K, tmp, risposta = 0;
    cin >> N >> K;

    multiset<int> C;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        C.insert(tmp);
    }

    int diff;
    multimap<int, multiset<int>::iterator> diffPtrs;
    multiset<int>::iterator it;
    for (it = next(C.begin()); it!= C.end(); ++it) {
        diff = *it;
        it--;
        diff -= *it;
        it++;
        diffPtrs.insert(make_pair(diff, it));
        cout << *it << " ";
        cout << diff << "\n";
    }
    for (it = next(C.begin()); it!= C.end(); ++it) {
        diff = *it;
        it--;
        diff -= *it;
        it++;
        diffPtrs.insert(make_pair(diff, it));
        cout << *it << " ";
        cout << diff << "\n";
    }


    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    // freopen("collezionismo_input_1.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}