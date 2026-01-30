#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#pragma once

typedef struct person_s {
  // fields
  char *name;
  char *address;

  // functions
  char *(*get_name)(struct person_s *);
  char *(*get_address)(struct person_s *);
  void (*free)(struct person_s *);
} person_t;

person_t *person(char *name, char *address);

char *person_get_name(person_t *_this);
char *person_get_address(person_t *_this);

void person_free(person_t *_this);
