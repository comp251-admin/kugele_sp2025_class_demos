#include <stdio.h>

void init_array(int array[], int size, int value) {
  int i;
  for (i = 0; i < size; i++) {
    array[i] = value;
  }
}

void print_array(int array[], int size) {
  printf("\tarray: %p\n", array);
  printf("\t&array[0]: %p\n", &array[0]);

  puts("");

  int i;
  for (i = 0; i < size; i++) {
    printf("\tarray[%d]: %d\n", i, array[i]);
  }
}

int main(void) {
  int n = 5;
  int arr[5];

  // question: what are the array values initialized to by the compiler?
  printf("values before init:\n");
  print_array(arr, n);

  puts("---------------------------");

  // question: what is being passed to the function in the first parameter?
  // question: why are we passing the array's size?
  init_array(arr, n, 1);

  printf("values after init:\n");
  print_array(arr, n);

  // question: what happens if this is executed?
  // printf("arr[5]: %d\n", arr[5]);
  
  // question: what happens if this is executed?
  // printf("arr[-1]: %d\n", arr[-1]);
  
  // question: what is the sizeof(arr)?
  // question: what if we executed this inside of a function?
  // printf("sizeof(arr): %lu\n", sizeof(arr));

  return 0;
}
