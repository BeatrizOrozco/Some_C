#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[]){
	
	
	FILE *inputfile;
	FILE *outputfile1;
	FILE *outputfile2;
	char ch;
	int size=0;
	int *seq;
	int i=0;
	int count1=0;
	
	inputfile = fopen(argv[1], "r");
	while((ch = fgetc(inputfile)) != EOF){
	 size++;
	}
	fclose(inputfile);
	
	if(!(seq=malloc(size*sizeof(char)))){
	 fprintf(stderr, "Problema con la reserva de memoria\n");
   	 exit(1);
 	}

	inputfile = fopen(argv[1], "r");
	for (i = 0; i < size; i++){
         fscanf(inputfile, "%1d", &seq[i]);
        }	
	fclose(inputfile);
	/*
	for (i = 0; i < size; i++){
	 if(seq[i]==1){
		count1++;
	 }
	}*/	
	
	printf("%1d",size);
   	return 0;  
}
