#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <math.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>

#include <getpar.h>
#include <edacor.h>
#include <mandelbrot.h>

#define _div(x, y) (int)((double) (x) /(double) y)

// Reserva memoria para la matriz de la imagen
void buildmatrix() {
	int i;

	// Límite superior - límite inferior
	dimx = _div(par.c - par.a, par.s) +1;
	dimy = _div(par.d - par.b, par.s) +1;

					printf("Construyendo matriz de puntos [%d, %d] ... ", dimx, dimy);
	
	// Creacion de la memoria compartida
	shm_fd = shm_open("/matrix", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if(shm_matrix == -1) {
		printf("\n* Error fatal al intentar crear la memoria compartida\n");
		exit(1);
	}

	if (ftruncate(shm_fd, sizeof(double) * dimx * dimy) != 0) {
		printf("\n* Error fatal al intentar truncar la memoria compartida\n");
		exit(1);
	}
		

	// Mappeo de la memoria compartida para darle el tamaño
	matrix = (double *) mmap(NULL, sizeof(double) * dimx * dimy, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if(matrix == MAP_FAILED) {
		printf("\n* Error fatal al mapear la memoria compartida\n");
		exit(1);
	}

					printf("OK\n");
}

// Complex to matrix (Número complejo a posición de la matriz)
int * ctom(double x, double y) {
	int * res = (int *) malloc(sizeof(int) * 2);
	res[0] = _div(x - par.a, par.s);
	res[1] = _div(y - par.b, par.s);
	return res;
}

// Matrix to complex (Posición de la matriz a número complejo)
double * mtoc(int corx, int cory) {
	double * res = (double *) malloc(sizeof(double) * 2);	
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
	return res;
}

// Escribe la matriz en bruto (BYTE)
void writeoutput() {
	// printf("Escribiendo archivo de salida %s\n", par.f);
	FILE * fd = fopen(par.f, "wb");
	int * it;
	int i;
	for(i = 0; i < dimx * dimy; i++) {
		it = itom(i);
		fwrite((double *) &matrix[mtoi(it[0], it[1])], sizeof(double), 1, fd);
	}
	free(it);
	fclose(fd);
}

// Función realizada para testeo unitario
void edacortest() {
	int i;
	int * it;
	double * itm;
	for(i = 0; i < dimx * dimy; i++) {
		// Transformación de número a coordenada de matriz
		it = itom(i);

		// Transformación de coordenada de matriz a coordenada compleja
		itm = mtoc(it[0], it[1]);

		mandelbrotjob(i);
		// printf("Visitando el job nro. %d\ten [%d, %d]\tcomplex [%f, %f] = \t%f\n", i, it[0], it[1], itm[0], itm[1], matrix[it[0]][it[1]]);
		
		free(it);
		free(itm);
	}
}