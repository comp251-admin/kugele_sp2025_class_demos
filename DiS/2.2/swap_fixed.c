#include <stdio.h>

void swap(int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

int main(void) {
  int a = 5, b = -137;

  printf("a: %d\tb: %d\t(BEFORE)\n", a, b);
  swap(&a, &b);
  printf("a: %d\tb: %d\t(AFTER)\n", a, b);

  return 0;
}
