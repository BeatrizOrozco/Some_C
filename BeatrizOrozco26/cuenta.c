/* Se va a generar una distribucion normal usando N, mu y sig como inputs
en donde N es el numero de muestras
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/* --------CONSTANTES GLOBALES------------------------------- */

#define  N 4

int main(int argc, char * argv[]){
	
	
	char *inputname;
	char *outputname1;
	char *outputname2;
	FILE *inputfile;
	FILE *outputfile1;
	FILE *outputfile2;
	inputname = argv[1];
	outputname1 = argv[2];
	outputname2 = argv[3];
 	int *seq;
	float elapsed=0;
	int i,idx1=0,idx2 = 0;
	int boole;
	int count1=0,count2=0,count3=0,count4=0,count5=0;
	char ch;
	int size=0;
	int c1=1;
	int c12[2]={1,2};
	int c123[3]={1,2,3};
	int c1234[4]={1,2,3,4};
	
	clock_t start = clock();

        inputfile = fopen(inputname,"r");

	while((ch = fgetc(inputfile)) != EOF){
		size++;
	}

	seq=malloc(size*sizeof(char));
	
	for (idx1 = 0; idx1 < size; idx1++){
        fscanf(inputfile, "%1d", &(seq[idx1]));
    	}
	
	for (idx1=0;idx1<size;idx1++){
		if (seq[idx1]==1){
			count1++;
		}
	}

	for(idx1=0;idx1<size;idx1++){
	boole=0;
		for (idx2=0;idx2<2;idx2++){
			if (seq[idx1+idx2]==c12[idx2]){
				boole++;
			}
		}
		if (boole==2){
			count2++;
		}
	}

	for(idx1=0;idx1<size;idx1++){
		boole=0;
		for (idx2=0;idx2<3;idx2++){
			if (seq[idx1+idx2]==c123[idx2]){
				boole++;
			}
		}
		if (boole==3){
			count3++;
		}
	}

	for(idx1=0;idx1<size;idx1++){
		boole=0;
		for (idx2=0;idx2<4;idx2++){
			if (seq[idx1+idx2]==c1234[idx2]){
				boole++;
			}
		}
		if (boole==4){
			count4++;
		}
	}
                

	fclose(inputfile); 
	clock_t stop = clock();
	
    	elapsed = (double)(stop - start)/ CLOCKS_PER_SEC;
	
	outputfile1 = fopen(outputname1,"w");
	for(i=0;i<4;i++){
    		fprintf(outputfile1, "%d\n,%d\n,%d\n,%d\n,", count1,count2,count3,count4);
	}	
	fclose(outputfile1);

	outputfile2 = fopen(outputname2,"w");
	fprintf(outputfile2, "%f", elapsed);
	fclose(outputfile2); 
	
	
   	return 0;  
}
