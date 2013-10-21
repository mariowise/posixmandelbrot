#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <time.h>

#include <getpar.h>
#include <edacor.h>
#include <mandelbrotp.h>

int main(int argc, char * argv[]) {

	time_t start, end;
	time(&start);
	srand(time(NULL));

	// Lectura de parámetros
	getpar(argc, argv);

	// Construcción de la matriz de puntos
	buildmatrix();

	// Comienza el trabajo en paralelo
	mandelbrot_parallel();

	// printf("Comenzando escritura de la salida\n");

	// Escribir la salida en el archivo output
	writeoutput();

	time(&end);

	double runtime = (double) difftime(end, start);
	printf("Ejecución completada en %.2lf segundos con %d procesos\n", runtime, par.t);

	shm_unlink("/matrix");

	return EXIT_SUCCESS;
}