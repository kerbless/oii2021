//https://training.olinfo.it/#/task/ioit_spam/statement
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int nbad;
    cin >> nbad;
    string bad[nbad], tmpString;
    for (int i = 0; i < nbad; i++) {
        cin >> tmpString;
        bad[i] = tmpString;
    }

    int ngood;
    cin >> ngood;
    string good[ngood];
    for (int i = 0; i < ngood; i++) {
        cin >> tmpString;
        good[i] = tmpString;
    }

    int nmail, nwords, goodmails = 0, badmails = 0;
    cin >> nmail;
    for (int i = 0; i < nmail; i++) { // for every mail
        bool positive = false, negative = false;
        cin >> nwords;
        for (int j = 0; j < nwords; j++) { // for every word
            cin >> tmpString; // take word
            if (!positive) { // if no positive found yet
                for (int k = 0; k < ngood; k++) { // test all good words
                    if (tmpString == good[k])  {
                        //cout << "found good word \"" << tmpString << "\" in mail " << i+1 << endl; 
                        positive = true;
                        break;
                    }
                }
            }
            if (!negative) { // if no negative found yet
                for (int k = 0; k < nbad; k++) {
                    if (tmpString == bad[k])  {
                        //cout << "found bad word \"" << tmpString << "\" in mail " << i+1 << endl; 
                        negative = true;
                        break;
                    }
                }
            }
            if (positive && negative) break; //dubious
        }
        if (!(positive && negative )) { // not dubious
            if (positive) goodmails += 1;
            else if (negative) badmails += 1;
        }
    }

    cout << badmails << " " << goodmails;
    return 0;
}
