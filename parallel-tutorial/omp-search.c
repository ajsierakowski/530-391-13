#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argn, char* argv[]) {
  // error checking
  if(argn < 3) {
    printf("Usage: ./serial-search N np\n");
    return EXIT_FAILURE;
  }

  // set up random number generator
  time_t t;
  srand(1);//(unsigned) time(&t));

  // set up array
  int n = atoi(argv[1]);
  int np = atoi(argv[2]);
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
  // openMP search
  int sub_max[np];
  for(i = 0; i < np; i++) {
    sub_max[i] = 0;
  }
  int max = 0;

  #pragma omp parallel num_threads(np)
  {
    for(j = 0; j < 1000; j++) {
      // setting up the search
      int tid = omp_get_thread_num();
      int k = 0;
      int split = n / np;

      // do search over this thread's piece
      for(k = tid*split; k < (tid+1)*split; k++) {
        //printf("tid = %d i = %d\n", tid, i);
        if(A[k] > sub_max[tid]) {
          sub_max[tid] = A[k];
        }
      }
      for(i = 0; i < np; i++) {
        if(sub_max[i] > max) {
          max = sub_max[i];
        }
      }    

      if(j == 999) {
        printf("The maximum is %d\n", max);
      }
    }
  }
  diff = clock() - start;

  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("Time taken %d.%d seconds\n", msec/1000, msec%1000);

  return EXIT_SUCCESS;
}
