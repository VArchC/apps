#include <stdio.h>
#include <stdlib.h>

#ifndef DATATYPE
#define DATATYPE int
#endif

int main(int argc, char* argv[]) {
  const int size;
  DATATYPE *A, *B, *C;
  int i, j, k;

  scanf("%d", &size);

  //Allocate memory for input matrices
  A = calloc(size * size, sizeof(DATATYPE));
  B = calloc(size * size, sizeof(DATATYPE));

  //Allocate memory for resulting matrix
  C = calloc(size * size, sizeof(DATATYPE));

  // Read input A
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      scanf("%d", &(A[i*size + j]));
    }
  }

  // Read input B
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      scanf("%d", &(B[i*size + j]));
    }
  }

  // Multiply
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      C[i*size + j] = 0;
      for (k = 0; k < size; k++) {
        C[i*size + j] += A[i*size + k] * B[k*size + j];
      }
    }
  }

  // Print output C
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%d\n", C[i*size + j]);
    }
  }

  return 0;
}
