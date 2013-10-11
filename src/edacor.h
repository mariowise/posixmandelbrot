#ifndef EDACOR_H_
#define EDACOR_H_

// Image matrix

int dimx, dimy;

float ** matrix;

void buildmatrix();

int * ctom(float x, float y);

int * ctom(float x, float y);

int mtoi(int corx, int cory);

int * itom(int jobno);

#endif