#include <stdio.h>

#define PI 3.14159265358979323

int main(void){
  /*
   * declaration of variables
   **************************/
  int x;

  // multiple variables declared on a single line
  long i,j,k;

  char letter; // ascii encoded

  // double is more precise than float
  float w;
  double pi;

  /*
   * initialization of variables
   *****************************/
  x = 7;

  /* 
   * chained assignment
   *
   * question: why does this work???
   */
  i = j = k = x + 2;

  /* 
   * notice that this uses single quotes not double quotes
   *
   * question: what happens when we add or subtract from char values?
   */
  letter = 'A';
  letter += 1;

  printf("letter: %c\tascii code: %d\n", letter, letter);

  // doubles have greater precision than floats
  w = PI;
  pi = PI;

  // comparing the precision of float and double
  printf("w:%.15g\n", w);
  printf("pi:%.15g\n", pi);

  /***********************************
   * in general -- don't use floats! *
   ***********************************/

  // what is the value here?
  j = 11 / 2;

  // declaring and initializing a variable in a single line
  unsigned int altuae = 42;

  // question: what is happening here with the decrement and increment
  // operators!?!
  long long big = --x + i++ + 1;

  /*
   * question: how many bytes do these types require in memory???
   *
   */
  printf("size: %lu\n", sizeof(letter));
  printf("size: %lu\n", sizeof(big));

  return 0;
}
