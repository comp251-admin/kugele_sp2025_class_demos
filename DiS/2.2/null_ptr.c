#include <stdlib.h>
#include <stdio.h>

int main() {
  int *p_int = NULL; /* uninitialized */

  printf("p_int's value: %p\n", p_int);
  printf("p_int's size: %lu\n", sizeof(p_int));
  printf("p_int's location: %p\n", &p_int);

  printf("*p_int (before assignment): %d\n", *p_int);

  *p_int = 10;

  printf("*p_int (after assignment): %d\n", *p_int);

  return 0;
}
