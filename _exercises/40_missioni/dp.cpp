//https://training.olinfo.it/#/task/missioni/submissions<Paste>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n; in >> n;
    n++; //compensate for the manually added zeros at index 0 (meet by i = 1!)

    //d = days needed; s = day limit; r = days used; x = missions done
    int d[n] = {0}, s[n] = {0}, r[n] = {0}, x[n] = {0}; 
    
    for (int i = 1; i < n; i++)
        in >> d[i] >> s[i];
    
    //the real stuff
    int mx = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            out << i << " " << j << " ";
            if (x[j] + 1 > x[i]) { //useful
                out << "useful "; 
                if (r[j] + d[i] <= s[i]) { //doable
                    out << "doable "; 
                    r[i] = r[j] + d[i];
                    x[i] = x[j] + 1;
                }
            }
            out << "\n";
        } 
        if (x[i] > mx) mx = x[i];
    }
    
    //DEBUG
    for (int i = 0; i < n; i++)
        out << d[i] << " " << setw(2) << s[i] << " " << setw(2) << r[i] << " " << setw(2) << x[i] << "\n";
    
    out << mx;
    return 0;
 }
