#include <stdio.h>
#include <stdlib.h>

FILE *in, *out;

void openIO();
void closeIO();

int main(){
	int i, tmp, howmany, sum = 0;
	
	openIO();
	fscanf(in, "%d", &howmany);
	for (i = 0; i < howmany; i++) { // starts where the previous fscanf left, so no need to do a i+1 or i=1
		fscanf(in, "%d", &tmp); 
		sum += tmp;
	}
	fprintf(out, "%d", sum);
	printf("%d", sum);
	
	return 0;
}

void openIO() {
	in = fopen("input.txt", "r");
	if (in == NULL) {
	    printf("Error while opening input file");
	    exit(100);
	}
	out = fopen("output.txt", "w");
	if (out == NULL) {
	    printf("Error while opening output file");
	    exit(100);
	}
}

void closeIO() {
	int fcloseReturn;
	
	fcloseReturn = fclose(in);
	if (fcloseReturn != 0) {
		printf("Encountered error while closing input file");
		exit(101);
	}
	fcloseReturn = fclose(out);
	if (fcloseReturn != 0) {
		printf("Encountered error while closing output file");
		exit(101);
	}
}
