#include <stdio.h>

struct student_s {
  char name[61];
  float gpa;
};

int main(void) {
  struct student_s s;

  printf("sum of individual field sizes: %zu\n",
         sizeof(s.name) + sizeof(s.gpa));
  printf("total struct size: %zu\n", sizeof(s));

  return 0;
}
