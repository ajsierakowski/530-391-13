#include <stdio.h>

#include "readwrite.h"

void read(char *fname, float *a, float *b, float *c) {
  // open file
  FILE *fin = fopen(fname, "r");

  // read file
  fscanf(fin, "a = %f\n", a);
  fscanf(fin, "b = %f\n", b);
  fscanf(fin, "c = %f\n", c);

  printf("a = %f\nb = %f\nc = %f\n", *a, *b, *c);

  // close file
  fclose(fin);
}

void write(char *fname, float *x, float *y, int N){
  FILE *fout = fopen(fname, "w");

  fprintf(fout, "x y\n");
  for(int i = 0; i < N; i++) {
    fprintf(fout, "%f %f\n", x[i], y[i]);
  }

  fclose(fout);
}
