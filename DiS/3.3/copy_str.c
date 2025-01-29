#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *copy(char* src);

int main(void){
  char *str = "hello world!";
  char *cpy = NULL;

  cpy = copy(str);
  printf("%s\n", cpy);

  free(cpy);
}

char *copy(char* src){
  char *cpy = strdup(src);

  // make another copy
  char *another = cpy;
  printf("another: %s\n", another);

  // free memory from 2nd copy
  free(another);

  // return 1st copy
  return cpy;
}
