#include "intersect.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum dir_e { LEFT, RIGHT, STRAIGHT, STOP } dir_t;

typedef struct step_s {
  intersect_t inter;
  dir_t dir;
  struct step_s *next;
} step_t;

void display_route(step_t *step) {
  step_t *curr = step;

  while (curr != NULL) {
    printf("%s (dir:%d)\n", curr->inter.desc, curr->dir);
    curr = curr->next;
  }
}

step_t *create_step(intersect_t inter, dir_t dir) {
  step_t *new = malloc(sizeof(step_t));
  if (new == NULL) {
    perror("malloc failed!");
    exit(1);
  }

  new->inter = inter;
  new->dir = dir;
  new->next = NULL;

  return new;
}

void add_step_to_route(step_t *ref, step_t *new) {
  new->next = ref->next;
  ref->next = new;
}

step_t *remove_next(step_t *ref) {
  step_t *to_remove = ref->next;
  if (to_remove != NULL) {
    ref->next = ref->next->next;
  }
  return to_remove;
}

int main(void) {

  step_t *step_1 = create_step(A, LEFT);
  step_t *step_2 = create_step(B, RIGHT);
  step_t *step_3 = create_step(C, STRAIGHT);
  step_t *step_4 = create_step(D, STRAIGHT);
  step_t *step_5 = create_step(E, LEFT);
  step_t *step_6 = create_step(F, STOP);

  step_1->next = step_2;
  step_2->next = step_3;
  step_3->next = step_4;
  step_4->next = step_5;
  step_5->next = step_6;

  step_t *step_3b = create_step(L, STRAIGHT);

  add_step_to_route(step_3, step_3b);

  printf("BEFORE: \n");
  display_route(step_1);

  step_t *to_remove = remove_next(step_3);
  free(to_remove);

  printf("AFTER: \n");
  display_route(step_1);

  return 0;
}
