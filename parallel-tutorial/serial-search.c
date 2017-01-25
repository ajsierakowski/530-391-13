#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argn, char* argv[]) {
  // error checking
  if(argn == 1) {
    printf("Usage: ./serial-search N\n");
    return EXIT_FAILURE;
  }

  // set up random number generator
  time_t t;
  srand(1);//(unsigned) time(&t));

  // set up array
  int n = atoi(argv[1]);
  int A[n];
  int i = 0;
  for(i = 0; i < n; i++) {
    A[i] = rand();
    //printf("A[%d] = %d\n", i, A[i]);
  }

  // repeat 1,000 times
  int j = 0;
  clock_t start = clock();
  clock_t diff;
  for(j = 0; j < 1000; j++) {
    // serial search
    int max = 0;
    for(i = 0; i < n; i++) {
      if(A[i] > max) {
        max = A[i];
      }
    }
    if(j == 999) {
      printf("The maximum is %d\n", max);
    }
  }
  diff = clock() - start;

  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("Time taken %d.%d seconds\n", msec/1000, msec%1000);

  return EXIT_SUCCESS;
}
