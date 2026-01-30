#include <stdio.h>

struct student_s {
  char name[61];
  float gpa;
};

int main(void) {
  struct student_s s;
  s = {"Alice", 3.95};

  printf("name: %s\n", s.name);

  return 0;
}
