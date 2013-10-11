#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <getpar.h>
#include <edacor.h>

#include <stdbool.h>

int main(int argc, char * argv[]) {
	// Lectura de parámetros
	getpar(argc, argv);

	// Construcción de la matriz de puntos
	buildmatrix();

	return EXIT_SUCCESS;
}