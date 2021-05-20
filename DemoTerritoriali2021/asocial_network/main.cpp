#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    int N; cin >> N; // users
	int TMP;
    priority_queue< pair<int, int> > A;
    priority_queue< pair<int, int> > B;
    for (int i=0; i<N; i++) {
    	cin >> TMP;
        A.push(make_pair(-TMP, i));
        B.push(make_pair(TMP, i));
        
    }
	
	int i = 0, gave;
    vector<int> F(N, 0); // memorizza qui le risposte
    while(!A.empty()) {
    	gave = 0;
		//cout << " " << A.top().first << " " << A.top().second << " / " << B.top().first << " " << B.top().second << "\n";
    	while(gave < B.top().first) {
    		if(A.top().second != B.top().second) {
    			F[A.top().second] = B.top().second;
    			//cout << A.top().second << " followed " << B.top().second << "\n";
    			gave++;
			}
    		A.pop();    		
		}
		B.pop();
    	i++;
	}
    
    cout << "Case #" << t << ":";
    for (int i = 0; i < N; i++) {
        cout << " " << F[i];
    }
    cout << "\n";
}

int main() {
    freopen("social_input_2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        solve(t);
    }
}
