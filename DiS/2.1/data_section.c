#include <stdio.h>

/* globals */
int g_x = 1; // should be in data
int g_y;     // should be in bss

int display_counter(void) {
  static int counter = 1; // should be in data
  counter++;
  return counter;
}

int main(void) {
  printf("%d\n", display_counter());
  return 0;
}
