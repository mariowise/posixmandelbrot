#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <getpar.h>
#include <edacor.h>

#include <math.h>

#define _div(x, y) (int)round((double) (x) /(double) y)

// Reserva memoria para la matriz de la imagen
void buildmatrix() {
	int i;

	// Límite superior - límite inferior
	dimx = _div(par.c - par.a, par.s) +1;
	dimy = _div(par.d - par.b, par.s) +1;

					printf("Construyendo matriz de puntos [%d, %d]\n", dimx, dimy);
	
	// Memoria para la primera dimensión de la matriz
	matrix = (float **) malloc(sizeof(float*) * dimx);

	// Memoria para la segunda dimensión de la matriz
	for(i = 0; i < dimx; i++)
		matrix[i] = (float *) malloc(sizeof(float) * dimy);
}

// Complex to matrix (Número complejo a posición de la matriz)
int * ctom(float x, float y) {
	int * res = (int *) malloc(sizeof(int) * 2);
	res[0] = _div(x - par.a, par.s);
	res[1] = _div(y - par.b, par.s);
	return res;
}

// Matrix to complex (Posición de la matriz a número complejo)
float * mtoc(int corx, int cory) {
	float * res = (float *) malloc(sizeof(float) * 2);	
	res[0] = par.a + corx * par.s;
	res[1] = par.b + cory * par.s;
	return res;
}

// Matrix to integer (Posicion de la matriz a un número único tipo turno|job)
int mtoi(int corx, int cory) {
	return corx * dimy + cory;
}

// Integer to matrix (Número único a posicion de la matriz)
int * itom(int jobno) {
	int * res = (int *) malloc(sizeof(int) * 2);
	res[0] = jobno / dimy;
	res[1] = jobno % dimy;
}