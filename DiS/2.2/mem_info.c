#include <stdio.h>

int main(void) {
  int a[5] = {5, 4, 3, 2, 1};
  int *p;
  p = a;

  printf("a: %p\n", a);
  printf("*a: %d\n", *a);
  printf("p: %p\n", p);
  printf("*p: %d\n", *p);
  printf("a[0]: %d\n", a[0]);
  printf("&a[0]: %p\n", &a[0]);
  printf("p[0]: %d\n", p[0]);
  printf("&p[0]: %p\n", &p[0]);
  printf("&a: %p\n", &a);
  printf("&p: %p\n", &p);

  return 0;
}
