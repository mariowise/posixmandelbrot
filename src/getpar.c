#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <getpar.h>

// Obtiene los parámetros con getopt
void getpar(int argc, char * argv[]) {
	int opt;
	
	while ((opt = getopt(argc, argv, "p:a:b:c:d:s:f:")) != -1) {
		switch (opt) {
			case 'p':
				par.p = atoi(optarg);
				par.check[0] = 1;
				break;
			case 'a':
				par.a = atoi(optarg);
				par.check[1] = 1;
				break;
			case 'b':
				par.b = atoi(optarg);
				par.check[2] = 1;
				break;
			case 'c':
				par.c = atoi(optarg);
				par.check[3] = 1;
				break;
			case 'd':
				par.d = atoi(optarg);
				par.check[4] = 1;
				break;
			case 's':
				par.s = atof(optarg);
				par.check[5] = 1;
				break;
			case 'f':
				par.f = (char *) malloc(sizeof(char) * strlen(optarg));
				strcpy(par.f, optarg);
				par.check[6] = 1;
				break;
			default:
				fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	if (optind != argc) {
		fprintf(stderr, "Expected argument after options %d != %d\n", optind, argc);
		exit(EXIT_FAILURE);
	}
}

// Muestra los parámetros ingresados en la consola
void printpar() {
	printf(" -p: %d\n", par.p);
	printf(" -a: %d\n", par.a);
	printf(" -b: %d\n", par.b);
	printf(" -c: %d\n", par.c);
	printf(" -d: %d\n", par.d);
	printf(" -s: %f\n", par.s);
	printf(" -f: %s\n", par.f);
}