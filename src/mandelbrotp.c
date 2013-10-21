#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#include <getpar.h>
#include <edacor.h>
#include <mandelbrot.h>

// El thread se identifica a partir de threadId y el total de hebras corriendo warpsize
void mandelbrot_parallel_runner(int tid, int warpsize) {
	int c = 0, works = (dimx / warpsize + 1);
	int i = tid * works, j;
	while(i < dimx && c < works) {
		// printf(" thread %d procesando fila %d %p\n", tid, i, matrix);
		for(j = 0; j < dimy; j++)
			mandelbrotjob(mtoi(i, j));
		i++;
		c++;
	}
}

// Esta función intenta optimizar el trabajo dentro de la página de 4096 B = 256 double
void mandelbrot_parallel_runner2(int tid, int warpsize) {
	int i = tid;
	int jobcount = dimx * dimy;
	while(i < jobcount) {
		mandelbrotjob(i);
		i += warpsize;
	}
}

// Esta función reparte los job en pequeños saltos equidistantes de tamaño warpsize
void mandelbrot_parallel_runner3(int tid, int warpsize) {
	int i = tid, j;
	while(i < dimx) {
		for(j = 0; j < dimy; j++)
			mandelbrotjob(mtoi(i, j));
		i += warpsize;
	}
}

void mandelbrot_parallel() {

	int i, pid;
	for(i = 1; i < par.t; i++) {

		// Creación de un proceso
		pid = fork();

		if(pid == 0) { // Hijo
			
			pid = i;

			mandelbrot_parallel_runner3(pid, par.t);
			
			exit(0);

		}
	}

	// Hebra padre también trabaja
	mandelbrot_parallel_runner3(0, par.t);

	// Espera por todos los hijos para continuar
	while(wait(NULL) > 0);
}