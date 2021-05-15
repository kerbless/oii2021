#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int N, tmp, i, tot = 0, sum; cin >> N;
    priority_queue<int> nums;
    for (i = 0; i < N; i++) {
        cin >> tmp; tmp = tmp*-1;
        nums.push(tmp);
    }

    while (!nums.empty()) {
        if (nums.size() < 2) break;
        sum = nums.top();
        nums.pop();
        sum += nums.top();
        nums.pop();
        nums.push(sum);
        tot += sum;
    }

    cout << tot*-1;
    return 0;
}
