#include <bits/stdc++.h>
using namespace std;
int d[101], s[101], x[366];

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n; in >> n;
    for (int i = 0; i < n; i++)
        in >> d[i] >> s[i];

    for (int i = 0; i < n; i++)
        out << d[i] << " " << s[i] << "\n";

    for (int i=0; i<n; i++)
        for (int j = d[i]-s[i]; j >= 0; j--)
            if (x[j] + 1 > x[j+d[i]])
                d[j+d[i]] = x[j]+1;
    
    int max = x[0];
    for (int i=0; i<366; i++)
        if (x[i] > max) max = x[i];
    out << max;

    return 0;
 }
