#include <stdlib.h>
#include <stdio.h>

#include "readwrite.h"

int main(int argc, char *argv[]) {
  // print hello
  printf("Hello!\n");

  // parse command line arguments
  printf("There are %d command line arguments.\n", argc);
  printf("They are:\n");

  int i;
  for(i = 0; i < argc; i++) {
    printf("  %d: %s\n", i, argv[i]);
  }

  float f = 0.;
  printf("f = %f\n", f);
  f = 41.0;
  printf("f = %f\n", f);
  f = f / 3.;
  printf("f = %.20f\n", f);
  double g;
  g = 41.0 / 3.;
  printf("g = %.20f\n", g);

  // static array
  int A[10];

  // fill A and print
  for(i = 0; i < 10; i++) {
    A[i] = i;
    printf("A[%d] = %d\n", i, A[i]);
  }

  // variable-length array
  int B[argc];

  // fill B and print
  for(i = 0; i < argc; i++) {
    B[i] = i;
    printf("B[%d] = %d\n", i, B[i]);
  }

  // dynamically allocated array
  int *C; // telling c (language) that C (variable) is the beginning of a
          // sequence of integers
  if(argc > 1) {
    // get the length of the array from the command line
    int clen = atoi(argv[1]);

    // allocate C's memory
    C = malloc(clen * sizeof(int));

    // fill C and print
    for(i = 0; i < clen; i++) {
      C[i] = i;
      printf("C[%d] = %d\n", i, C[i]);
    }

    // clean up
    free(C);
  }

  // read a file
  float a = 0.;
  float b = 0.;
  float c = 0.;
  read("input", &a, &b, &c);

  printf("a = %f\nb = %f\nc = %f\n", a, b, c);

  int N = 10;
  float beg = -1.;
  float end = 1.;
  float delta = (end - beg) / ((float)N-1.);
  float *x = malloc(N * sizeof(float));
  float *y = malloc(N * sizeof(float));

  // SCIENCE
  for(i = 0; i < N; i++) {
    x[i] = beg + i * delta;
    y[i] = a*x[i]*x[i] + b*x[i] + c;
  }

  write("output", x, y, N);

  free(x);
  free(y);
  
  return EXIT_SUCCESS;
}
