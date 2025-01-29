#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_args(char **args);

int main(int argc, char **argv){
  int i = 0;
  char **argv_copy = malloc((argc + 1) * sizeof(char **));

  // NULL terminate array
  argv_copy[argc] = NULL;

  for (i = 0; i < argc; i++) {
    argv_copy[i] = strdup(argv[i]);
  }

  // original
  display_args(argv);

  // copy
  display_args(argv_copy);

  for (i = 0; i < argc; i++) {
    free(argv_copy[i]);
  }

  free(argv_copy);
}

void display_args(char **args){
  while (*args) {
    printf("%s\n", *args++);
  }
}
