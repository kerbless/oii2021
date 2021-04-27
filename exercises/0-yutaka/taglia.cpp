#include <cmath>

int taglia(int N, int V[]) {
    const unsigned int M = 1000000007; 

    unsigned int subComb;
    int comb = 0, subSize = 0;
    for (int i = 0; i < N; i++) {
        subSize++;
        if (V[i] == V[i+1] || i == N-1) {
            if (subSize != 1) {
                subComb = pow(2, subSize-1);
                comb += subComb % M;
            }
            subSize = 0;
        }
    }
    if (comb == 0) comb = 1 % M;
    return comb;
}
