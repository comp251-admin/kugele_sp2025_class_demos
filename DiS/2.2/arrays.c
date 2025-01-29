#include <stdio.h>

#define N_CHARS 5
#define N_INTS 3

void iterate_char_array(int n , char *array) {
  printf("array: \n");
  for (int i = 0; i < N_CHARS; i++) {
    printf("\t&array[%d]: %p\n", i, &array[i]);
    printf("\tarray[%d]: %d\n", i, array[i]);
    printf("\t*(array + %d): %d\n", i, *(array + i));
  }
}

void iterate_int_array(int n, int *array) {
  printf("array: \n");
  for (int i = 0; i < N_INTS; i++) {
    printf("\t&array[%d]: %p\n", i, &array[i]);
    printf("\tarray[%d]: %d\n", i, array[i]);
    printf("\t*(array + %d): %d\n", i, *(array + i));
  }
}

int main(void) {
  char char_array[N_CHARS + 1] = {'h','e','l','l','o','\0'};
  int int_array[N_INTS] = {10, -37, 2000001};

  /* passing the name of an array gives a pointer to its first element */
  iterate_char_array(N_CHARS, char_array);
  iterate_int_array(N_INTS, int_array);

  return 0;
}
