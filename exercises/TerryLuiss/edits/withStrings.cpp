#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int T; cin >> T;
    string line, result;
    int insertOffset = 0;
    for(int i = 0; i < T; i++) {
        cin >> line;
        for(int j = 0; j < line.size(); j++) {
        	//cout << j << " " << line[j] << line[j+1] << line[j+2] << " "; // debug
			if(line[j] == '[') {
				if(line[j+1] == 'R' && insertOffset < 0) insertOffset++;
            	if(line[j+1] == 'L' && -insertOffset < result.size()) insertOffset--;
            	if(line[j+1] == 'C' && !result.empty() && (result.size()+insertOffset != 0)) result.erase(result.end()-1+insertOffset);
				j += 2;
			}
            else result.insert(result.end()+insertOffset, line[j]);
            //cout << result << " " << result.size() << ">" << -insertOffset << " " << result.size()+insertOffset << "\n"; //debug
        }
        cout << "Case #" << i << ": " << result << "\n";
        result.clear();
        insertOffset = 0;
    }
    
}
