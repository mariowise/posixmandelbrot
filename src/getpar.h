#ifndef GETPAR_H_
#define GETPAR_H_

struct _par {
	// Número máximo de iteraciones
	int p;	// Depth o profundidad de búsqueda

	// Parámetros de dimensión del plano a trabajar
	int a;	// Límite inferior del componente real del plano
	int b;	// Límite inferior del componente imaginario del plano
	int c;	// Límite superior del componetne real del plano
	int d;	// Límite superior del componente imaginario del plano

	// Muestreo
	double s;	// Step o longitud del paso

	// nombre del archivo de salida
	char * f;

	// Número de hebras o workers
	int t;

	// Arreglo de booleanos para saber si se ingresaron todos los parámetros
	int check[7];

} par;

void getpar(int argc, char * argv[]);

void printpar();

#endif