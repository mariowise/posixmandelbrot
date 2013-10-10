#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <getpar.h>

int main(int argc, char * argv[]) {
	getpar(argc, argv);
	printpar();
}