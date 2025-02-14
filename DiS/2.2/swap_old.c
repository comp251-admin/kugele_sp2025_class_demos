#include <stdlib.h>
#include <stdio.h>

void swap_with_values(int x, int y) {
  int t;

  t = x;
  x = y;
  y = t;
}

void swap_with_ptrs(int *x, int *y){
  int t;

  t = *x;
  *x = *y;
  *y = t;
}

int main(void){
  int x = 5, y = -137;
  int *x_ptr = NULL, *y_ptr = NULL;

  /* swap without pointers */
  printf("x: %d\ty: %d\t(before swap_with_values)\n", x, y);
  swap_with_values(x, y);
  printf("x: %d\ty: %d\t(after swap_with_values)\n", x, y);

  printf("\n");

  x_ptr = &x;
  y_ptr = &y;

  /* swap with pointers */
  printf("x: %d\ty: %d\t(before swap_with_ptrs)\n", x, y);
  swap_with_ptrs(x_ptr, y_ptr);
  printf("x: %d\ty: %d\t(after swap_with_ptrs)\n", x, y);
 
  return 0;
}
