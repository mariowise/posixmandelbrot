#ifndef MANDELBROTP_H_
#define MANDELBROTP_H_

void mandelbrot_parallel_runner(int tid, int warpsize);

void mandelbrot_parallel_runner2(int tid, int warpsize);

void mandelbrot_parallel_runner3(int tid, int warpsize);

void mandelbrot_parallel();


#endif