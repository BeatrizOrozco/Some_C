sample.pdf: plot.py sample_1.dat sample_2.dat sample_3.dat sample_4.dat 
	python3 plot.py 

sample_1.dat sample_2.dat sample_3.dat sample_4.dat: adveccion.x 
	./adveccion.x

adveccion.x: adveccion.c
	cc adveccion.c -lm -o adveccion.x

