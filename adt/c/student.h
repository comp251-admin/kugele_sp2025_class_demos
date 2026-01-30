#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct student_s {
  /* fields */
  char *name;
  char *address;
  char *id;
  double gpa;

  /* functions */
  char *(*get_name)(struct student_s *);
  char *(*get_address)(struct student_s *);
  char *(*get_id)(struct student_s *);
  double (*get_gpa)(struct student_s *);
  void (*free)(struct student_s *);
} student_t;

student_t *student(char *name, char *address, char *id, double gpa);

char *student_get_id(student_t *_this);
double student_get_gpa(student_t *_this);
char *student_get_name(student_t *_this);
char *student_get_address(student_t *_this);
void student_free(student_t *_this);
