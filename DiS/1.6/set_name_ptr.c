#include <stdio.h>
#include <string.h>

typedef struct student_s {
  char *name;
  double gpa;
} student_t;

void set_name(student_t s, char *new_name) { strcpy(s.name, new_name); }

int main(void) {
  student_t s1;

  s1.name = strdup("Alice");
  s1.gpa = 3.95;

  set_name(s1, "Bob");
  printf("name: %s\n", s1.name);
  return 0;
}
