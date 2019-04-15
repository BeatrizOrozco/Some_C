#!/bin/bash
#PBS -l nodes=1:intel:ppn=1, mem=1gb
#PBS -l walltime=00:10:00
#PBS -M be.orozco10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio28 

module load anaconda/python3
cd $PBS_O_WORKDIR
make -f make.mk
mpirun -np 10 ./BeatrizOrozco_Ejercicio28


mpicc integra.c -o integra.x
mpiexec -np 10 ./integra.x 1000
