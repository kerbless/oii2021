#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int T; cin >> T;
    string line;
    list<char> result;
    int insertOffset = 0;
    list<char>::iterator ins = result.end();
    for(int i = 0; i < T; i++) {
        cin >> line;
        for(int j = 0; j < line.size(); j++) {
        	//cout << j << " " << line[j] << line[j+1] << line[j+2] << " "; // debug
			if(line[j] == '[') {
				if(line[j+1] == 'R' && insertOffset < 0) insertOffset++;
            	if(line[j+1] == 'L' && -insertOffset < result.size()) insertOffset--;
            	if(line[j+1] == 'C' && !result.empty() && (result.size()+insertOffset != 0)) result.erase(next(prev(result.end()), insertOffset));
				j += 2;
			}
            else result.insert(next(result.end(), insertOffset), line[j]);
            // cout << j << endl;
            //if (j == 10000) break;
            //cout << result << " " << result.size() << ">" << -insertOffset << " " << result.size()+insertOffset << "\n"; //debug
        }
        cout << "Case #" << i << ": ";
        for (list<char>::iterator it = result.begin(); it != result.end(); it++) cout << *it;
        cout << "\n";
        result.clear();
        insertOffset = 0;
    }
    
}
