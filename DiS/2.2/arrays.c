#include <stdio.h>

#define n_chars 6
#define n_ints 3

void iterate_char_array(char *array) {
  printf("\nin iterate_char_array(char *array)\n\n");

  printf("\tarray: %p\n", array);
  printf("\tsizeof(array): %zu\n", sizeof(array));

  for (int i = 0; i < n_chars; i++) {
    printf("\t&array[%d]: %p", i, &array[i]);
    printf("\tarray[%d]: %3d('%c')", i, array[i], array[i]);
    printf("\t*(array + %d): %3d('%c')\n", i, *(array + i), *(array + i));
  }
}

void iterate_int_array(int *array) {
  printf("\nin iterate_int_array(char *array)\n\n");

  printf("\tarray: %p\n", array);
  printf("\tsizeof(array): %zu\n", sizeof(array));

  for (int i = 0; i < n_ints; i++) {
    printf("\t&array[%d]: %p", i, &array[i]);
    printf("\tarray[%d]: %8d", i, array[i]);
    printf("\t*(array + %d): %8d\n", i, *(array + i));
  }
}

int main(void) {
  char char_array[n_chars] = {'h', 'e', 'l', 'l', 'o', '\0'};
  int int_array[n_ints] = {10, -37, 2000001};

  printf("\nin main()\n\n");

  printf("\tchar char_array[%d] = {'h', 'e', 'l', 'l', 'o', '\\0'}\n", n_chars);
  printf("\tint int_array[%d] = {10, -37, 2000001}\n\n", n_ints);

  printf("\tsizeof(char) = %zu\n", sizeof(char));
  printf("\tsizeof(int) = %zu\n", sizeof(int));
  printf("\tsizeof(char *) = %zu\n", sizeof(char *));

  printf("\tsizeof(char_array) = %zu\n", sizeof(char_array));
  printf("\tsizeof(int_array) = %zu\n", sizeof(int_array));

  /* passing the name of an array gives a pointer to its first element */
  iterate_char_array(char_array);
  iterate_int_array(int_array);

  return 0;
}
