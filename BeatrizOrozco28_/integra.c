#include<iostream>
#include<cmath>
#include<vector>
#include<random>
#include "mpi.h"

double funcion(double *x);

int main(int argc, char *argv[])
{
  std::mt19937 generator(1);
  double lowlim = 0.0;
  double uplim = 1.0;
  int i=0;
  int j=0;
  int k=1;
  int dest, size, rank, tag;
  int N = atoi(argv[1]);
  int dimdelpunto=10;
  MPI_Status status;
  double area, ydex, deltadex, total, range, lower;
  double lista[dimdelpunto];
  
  for (i; i <  dimdelpunto; i++)
    {
      lista[i]=0.0; 
    }
  
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  range = (uplim - lowlim) / size;
  deltadex = range /(double) N;
  

  area=0.0;
  std::uniform_real_distribution<double> number(lowlim,uplim);
  for (i;i<N; ++i)
    {
      for(j; j< dimdelpunto;++j)
	{
	  lista[j]= number(generator);
	}
      ydex = funcion(lista);
      area += ydex*deltadex;
    }


  tag = 0;
  if (0 == rank)
    { 
      total = area; 
      for (k; k < size; ++k)
  	{
  	  MPI_Recv(&area, 1, MPI_DOUBLE, k, tag, MPI_COMM_WORLD, &status);
  	  total += area;
  	}
      fprintf(stderr, "%25.16e\n", total);
    }
  else
    { 
      dest = 0; 
      MPI_Send(&area, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
    } 
  
  MPI_Finalize();

  
  return 0;
  
}

double funcion(double *x)
{
  double cuadrado=0.0;
  for(i; i<sizeof(x);i++)
    {
      cuadrado+= x[i]*x[i];
    }
  return 
do;
}
