//https://training.olinfo.it/#/task/missioni/statement
#include <bits/stdc++.h>
using namespace std;

int maxm = 0;

void solve(vector<int> d, vector<int> s, int n, int u, int i, int m) {
    cout << "@ ";
    if (m > maxm) maxm = m;
    cout <<"u"<<u<<" "<<"m"<<m<<" "<<"i"<<i<<"\n";
    if (i == n) return;
    if (maxm < m+n-i) { //maximum reached
        if (u != 0) solve(d, s, n, u, i+1, m); // skipping mission i
        if (u+d[i] <= s[i]) solve(d, s, n, u+d[i], i+1, m+1); // taking mission i (if possible)
    }
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<int> d(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> s[i];
    }
    solve(d, s, n, 0, 0, 0);
    cout << maxm;
    return 0;
}
