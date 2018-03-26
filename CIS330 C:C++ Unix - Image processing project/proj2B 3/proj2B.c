#include <stdio.h>
#include <stdlib.h>
#include <printf.h>

int main(int argc, char *argv[]){
	//open binary file
	FILE *f_in = fopen(argv[1], "r");
	FILE *f_out = fopen(argv[2], "w");
	

	//read binary file into array
	//fread(destination, size of chunk, number of chunks, file_ptr)
	int* A;
	A = (int*) malloc(25 * sizeof(int));

	int j,i;
	//print result of terminal
	for(j = 0; j < 45; j += 10){
		i = 0;
		fseek(f_in, sizeof(int) * j, SEEK_SET);
		fread(A, sizeof(int), 5, f_in);


		fprintf(f_out, "%d\n",  A[i]);
		fprintf(f_out, "%d\n",  A[i+1]);
		fprintf(f_out, "%d\n",  A[i+2]);
		fprintf(f_out, "%d\n",  A[i+3]);
		fprintf(f_out, "%d\n",  A[i+4]);
		
	}
	fclose(f_in);
	fclose(f_out); 
}
