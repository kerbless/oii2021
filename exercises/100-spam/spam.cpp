//https://training.olinfo.it/#/task/ioit_spam/statement
#include <bits/stdc++.h>
using namespace std;

inline bool check(string word, string set[], int count) {
    for (int i = 0; i < count; i++)
        if (word == set[i]) return true;
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    /* variables */
    int nwords; // will be used to store number of words in each email
    int goodmails = 0, badmails = 0; // result variables
    string word; // will store a word temporarily

    /* get the set of bad words */
    int nbad; cin >> nbad; // number of bad words
    string bad[nbad], tmpString; // array of bad words + temp var
    for (int i = 0; i < nbad; i++) cin >> bad[i];

    /* get the set of good words */
    int ngood; cin >> ngood;
    string good[ngood];
    for (int i = 0; i < ngood; i++) cin >> good[i];

    /* get number of emails */
    int nmail; cin >> nmail;

    /* for every email */
    for (int i = 0; i < nmail; i++) {
        bool goodword = false, badword = false; // reset flags for words
        cin >> nwords;

        /* for every word */
        for (int j = 0; j < nwords; j++) {
            cin >> word;

            if (goodword && badword) continue; // the email is dubious

            /* if no goodword found yet, test the current "j" word with all good words */
            if (!goodword) if(check(word, good, ngood)) goodword = true;

            /* if no badword found yet, test the current "j" word with all bad words */
            if (!badword) if(check(word, bad, nbad)) badword = true;
        }
        if (goodword && !badword) goodmails += 1;
        if (badword && !goodword) badmails += 1;
    }

    cout << badmails << " " << goodmails;
    return 0;
}
