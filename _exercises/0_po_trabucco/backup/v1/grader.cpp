#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "trabucco2.cpp"

#define MAXN 2000

static int N, M, K;
static int X[MAXN * MAXN], Y[MAXN * MAXN];

int main() {
	FILE * fin, * fout;
	fin = fopen("input0.txt", "r");
	fout = fopen("output.txt", "w");
	assert(fscanf(fin, "%d%d%d", &N, &M, &K) == 3);
	int k;
	for(k = 0; k < K; ++k) {
		assert(fscanf(fin, "%d%d", X + k, Y + k) == 2);
	}
	fprintf(fout, "%d\n", ContaPercorsi(N, M, K, X, Y));
	
	return EXIT_SUCCESS;
}
