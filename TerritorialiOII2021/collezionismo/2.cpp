#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N, K, tmp;
    cin >> N >> K;

    multiset<int> C;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        C.insert(tmp);
    }

    int diff, totdiff = 0;
    multiset<int>::iterator itm;
    priority_queue<int> diffs;
    //priority_queue<int>::iterator itpq;
    for (itm = next(C.begin()); itm!= C.end(); ++itm) {
        diff = *itm;
        itm--;
        diff -= *itm;
        itm++;
        diffs.push(diff);
        totdiff += diff;
        //cout << *itm << " " << diff << "\n";
    }
    int risposta = totdiff;
    //cout << "\n" << totdiff;
    for (int i = 1; i < K; i++) {
        //cout << "-" << diffs.top();
        risposta -= diffs.top();
        diffs.pop();
    }

    cout << "Case #" << t << ": " << risposta << "\n";
}

int main() {
    freopen("collezionismo_input_2.txt", "r", stdin);
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}