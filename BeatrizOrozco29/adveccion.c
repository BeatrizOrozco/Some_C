#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

  double t_max[4]={0.0,0.5,1.0,2.0};
  int rank[4]={1,2,3,4};
  double delta_x=0.05;
  double delta_t=0.5*delta_x;
  double L=4.0;
  int N_t;
  double N = L/delta_x + 1;
  int b;	
  b=N;
  double u[b];
  double x[b];
  int i,j,k,l; 
  char filename[128];
  FILE *out;
   
  for (i=0;i<b;i++) {
    u[i] = 0.0; 
    x[i] = (double)(i)*(double)(L)/(double)(b);
    if (x[i] < 2.0){
      u[i] = 1.0;
    }	
  }  

  double u_final[b]; 

  for (i=0;i<b;i++) {
    u_final[i] = u[i]; 
  }  
  
  for (l=0;l<4;l++){ 
    N_t=(t_max[l]/delta_t);  
    for(i=0;i<N_t;i++){
      for (j=0;j<b;j++){
        u_final[j+1]=0.5*(u[j+2]+u[j]);
        u_final[j+1]-=(0.5*delta_t/delta_x)*(0.5*u[j+2]*u[j+2] - 0.5*u[j]*u[j]);
        u[j]=u_final[j];
      }
    }

    sprintf(filename, "sample_%d.dat", rank[l]);
    if(!(out = fopen(filename, "w"))){
     fprintf(stderr, "Problema abriendo el archivo\n");
     exit(1);
    }
    for(i=0;i<b;i++){
      fprintf(out, "%f,%f\n", x[i],u_final[i]);
    }
    fclose(out);

  }

  return 0;
}


