#ifndef EDACOR_H_
#define EDACOR_H_

// Image matrix

int dimx, dimy;

double * matrix;

int shm_matrix;

int shm_fd;

void buildmatrix();

int * ctom(double x, double y);

double * mtoc(int corx, int cory);

int mtoi(int corx, int cory);

int * itom(int jobno);

void writeoutput();

void edacortest();

#endif