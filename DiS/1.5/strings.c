#include <stdio.h>
#include <string.h>

int main(void) {
  char c_str[10];

  c_str[0] = 'H';
  c_str[1] = 'e';
  c_str[2] = 'l';
  c_str[3] = 'l';
  c_str[4] = 'o';

  // question: what happens if you leave off the null character?
  c_str[5] = '\0';

  printf("string value: %s\n", c_str);
  printf("string length: %lu\n", strlen(c_str));

  // WATCH OUT: in practice you should never assign a string literal to a char[]!!!
  char another_str[10] = "not hello";

  printf("another_str (old value): %s\n", another_str);
  printf("another_str (old length): %lu\n", strlen(another_str));

  // be careful of the argument ordering on strcpy here (destination, source)
  strcpy(another_str, c_str);

  printf("another_str (new value): %s\n", another_str);
  printf("another_str (new length): %lu\n", strlen(another_str));

  // question: why does this work?
  if (! strcmp(c_str, another_str)) { 
    puts("strings are the same!!!");
  }
  else {
    puts("strings are different!!!");
  }

  return 0;
}
