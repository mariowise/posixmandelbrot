#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <getpar.h>

// Obtiene los parámetros con getopt
void getpar(int argc, char * argv[]) {
	int opt, i, flag = 0;
	
	// Punto de partida para la recepción de parámetros
	for(i = 0; i < 8; i++)
		par.check[i] = 0;
	
	while ((opt = getopt(argc, argv, "p:a:b:c:d:s:f:t:")) != -1) {
		switch (opt) {
			case 'p':
				par.p = atoi(optarg);
				par.check[0] = 1;
				break;
			case 'a':
				par.a = (double) atof(optarg);
				par.check[1] = 1;
				break;
			case 'b':
				par.b = (double) atof(optarg);
				par.check[2] = 1;
				break;
			case 'c':
				par.c = (double) atof(optarg);
				par.check[3] = 1;
				break;
			case 'd':
				par.d = (double) atof(optarg);
				par.check[4] = 1;
				break;
			case 's':
				par.s = (double) atof(optarg);
				par.check[5] = 1;
				break;
			case 'f':
				par.f = (char *) malloc(sizeof(char) * strlen(optarg));
				strcpy(par.f, optarg);
				par.check[6] = 1;
				break;
			case 't':
				par.t = atoi(optarg);
				par.check[7] = 1;
				break;
			default:
				fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	// Verificación de ingreso de parámetros
	for(i = 0; i < 7; i++) {
		if(par.check[i] != 1) {
			flag = 1;
			switch(i) {
				case 0:
					printf("* Error: el parámetro 'p' es obligatorio y no fue proporcionado.\n");
					break;
				case 1:
					printf("* Error: el parámetro 'a' es obligatorio y no fue proporcionado.\n");
					break;
				case 2:
					printf("* Error: el parámetro 'b' es obligatorio y no fue proporcionado.\n");
					break;
				case 3:
					printf("* Error: el parámetro 'c' es obligatorio y no fue proporcionado.\n");
					break;
				case 4:
					printf("* Error: el parámetro 'd' es obligatorio y no fue proporcionado.\n");
					break;
				case 5:
					printf("* Error: el parámetro 's' es obligatorio y no fue proporcionado.\n");
					break;
				case 6:
					printf("* Error: el parámetro 'f' es obligatorio y no fue proporcionado.\n");
					break;
			}
		}
	}

	if(flag == 1)
		exit(0);
	
	if(par.check[7] == 0) {
		par.t = 1;
	}

	if (optind != argc) {
		fprintf(stderr, "Expected argument after options %d != %d\n", optind, argc);
		exit(EXIT_FAILURE);
	}
}

// Muestra los parámetros ingresados en la consola
void printpar() {
	printf(" -p: %d\n", par.p);
	printf(" -a: %.15f\n", par.a);
	printf(" -b: %.15f\n", par.b);
	printf(" -c: %.15f\n", par.c);
	printf(" -d: %.15f\n", par.d);
	printf(" -s: %.15f\n", par.s);
	printf(" -f: %s\n", par.f);
	printf(" -t: %d\n", par.t);
}