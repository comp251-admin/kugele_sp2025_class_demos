/* Copyright (c) 2020, Dive into Systems, LLC (https://diveintosystems.org/)  */
#include <stdio.h>
#include <stdlib.h>
#include "max.h"

#define MAX 10

/* print size elms of array p with name name */
void print_array(int *p, int size, char *name);

int main(int argc, char *argv[]) {
  int *bigfish, *littlefish, i;

  // allocate space for two int arrays
  bigfish = (int *)malloc(sizeof(int) * MAX);
  littlefish = (int *)malloc(sizeof(int) * MAX);

  if (!bigfish || !littlefish) {
    printf("Error: malloc failed\n");
    exit(1);
  }

  for (i = 0; i < MAX; i++) {
    bigfish[i] = MAX + i;
    littlefish[i] = i;
  }

  print_array(bigfish, MAX, "bigfish");
  print_array(littlefish, MAX, "littlefish");

  for (i = 0; i < max; i++) {
    bigfish[i] = 66 + i;
  }
  printf("\nafter loop:\n");
  print_array(bigfish, MAX, "bigfish");
  print_array(littlefish, MAX, "littlefish");

  free(bigfish);
  free(littlefish);

  return 0;
}

void print_array(int *p, int size, char *name) {
  int i;
  printf("%s array:\n", name);
  for(i = 0; i < size; i++) {
    printf("%3d ", p[i]);
  }
  printf("\n");
}
