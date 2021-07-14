#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, max = 0;
    in >> n;
    int d[n], s[n];
    for (int i = 0; i < n; i++) {
        in >> d[i] >> s[i];
        if (s[i] > max) max = s[i];
    }
    max++; // using days as indexes means counting from 1
    int x[max] = {0};
    for (int i=0; i<n; i++) {
        out << "_____" << i << "_____" << "\n";
        for (int j=s[i] - d[i]; j>=0; j--) {
        out << "j" << j << " " << j << "-" << j+d[i] << " " << x[j] + 1 << ">" << x[j+d[i]] << "? = " << x[j]+1 << "\n";
            if (x[j]+1 > x[j+d[i]]) {
                x[j+d[i]] = x[j]+1;
            }
        }
        for (int k = 0; k < max; k++)
            out << x[k];
        out << "\n";
    }

    int sol = x[0];
    for (int i=0; i< max; i++)
        if (x[i] > sol) sol = x[i];
    out << sol;
}
