#!/bin/bash
#PBS -l nodes=1:intel:ppn=8, mem=64gb
#PBS -l walltime=7:00:00:00
#PBS -M be.orozco10@uniandes.edu.co
#PBS -m abe
#PBS -N test1 


cd $PBS_O_WORKDIR
make 
./BeatrizOrozco27
./BeatrizOrozco27_

mpicc sample.c -o sample
mpirun -np 5 
