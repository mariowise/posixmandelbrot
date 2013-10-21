#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <math.h>

#include <getpar.h>
#include <edacor.h>
#include <mandelbrot.h>

// Aplica el algoritmo mandelbrot sobre un pixel
void mandelbrotjob(int jobid) {
	
	// Coordenadas de la matriz
	int * memcord = itom(jobid);

	// Coordenadas en el espacio complejo
	double * comcord = mtoc(memcord[0], memcord[1]);

	double zn[2], aux;

	int n = 1;

	// zn = 0 + c
	zn[0] = comcord[0];
	zn[1] = comcord[1];

	double length = sqrt((double) (zn[0] * zn[0] + zn[1] * zn[1]));

	// printf("n = %d\tz[n] = %f %fi\t length = %f\n", n, zn[0], zn[1], length);

	while(length < 2.0 && n < par.p) {
		aux = (zn[0] * zn[0]) - (zn[1] * zn[1]) + comcord[0];
		zn[1] = 2 * zn[0] * zn[1] + comcord[1];
		zn[0] = aux;

		length = sqrt((double) (zn[0] * zn[0] + zn[1] * zn[1]));		
		n++;

		// printf("n = %d\tz[n] = %f %fi\t length = %f\n", n, zn[0], zn[1], length);

		// sleep(1);
	}

	matrix[mtoi(memcord[0], memcord[1])] = log((double) n) + 1;

	free(memcord);
	free(comcord);
}
