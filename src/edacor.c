#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <getpar.h>
#include <edacor.h>

// Reserva memoria para la matriz de la imagen
void buildmatrix() {
	int i, dimx, dimy;

	// Límite superior - límite inferior
	dimx = (par.c - par.a) / par.s;
	dimy = (par.d - par.b) / par.s;	
	
	// Memoria para la primera dimensión de la matriz
	matrix = (float **) malloc(sizeof(float*) * dimx);

	// Memoria para la segunda dimensión de la matriz
	for(i = 0; i < dimx; i++)
		matrix[i] = (float *) malloc(sizeof(float) * dimy);
}

// Complex to matrix (Número complejo a posición de la matriz)
int * ctom(float x, float y) {
	int * res = (int *) malloc(sizeof(int) * 2);
	res[0] = (x - par.a) / par.s;
	res[1] = (y - par.b) / par.s;
	return res;
}

// Matrix to complex (Posición de la matriz a número complejo)
float * mtoc(int corx, int cory) {
	float * res = (float *) malloc(sizeof(float) * 2);
	res[0] = par.a + corx * par.s;
	res[1] = par.b + cory * par.s;
	return res;
}