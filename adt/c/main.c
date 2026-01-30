#include <stdio.h>

#include "person.h"
#include "student.h"

/* main driver */
int main(void) {
  student_t *s1 = student("John Doe", "456 Elm St.", "987654321", 3.75);

  printf("name: %s\n", s1->get_name(s1));
  printf("address: %s\n", s1->get_address(s1));
  printf("id: %s\n", s1->get_id(s1));
  printf("gpa: %f\n", s1->get_gpa(s1));

  person_t *p1 = person("John Doe", "456 Elm St.");

  printf("name: %s\n", p1->get_name(p1));
  printf("address: %s\n", p1->get_address(p1));

  s1->free(s1);
  p1->free(p1);

  return 0;
}
