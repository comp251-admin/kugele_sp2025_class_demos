#include <stdio.h>
#include <stdlib.h>

void dup_iarray(int **dest, int *src, int size) {
  *dest = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    (*dest)[i] = src[i];
  }
  free(*dest);
}

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  int *array = malloc(sizeof(int) * n);

  /* initialize the int array */
  for (int i = 0; i <= n; i++) {
    array[i] = i;
  }

  /* copy the int array */
  int *dup = NULL;
  dup_iarray(&dup, array, n);

  /* display both copy and original */
  for (int i = 0; i < n; i++) {
    printf("array[%d]: %d\t", i, array[i]);
    printf("dup[%d]: %d\n", i, dup[i]);
  }
  free(array);

  return 0;
}
