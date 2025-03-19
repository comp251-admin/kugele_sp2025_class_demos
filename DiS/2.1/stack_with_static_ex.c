#include <stdio.h>

int add_to_count(int n);

int main(void) {
  for (int i = 0; i < 5; i++) {
    printf("value: %d\n", add_to_count(1));
  }

  return 0;
}

int add_to_count(int n) {
  // static variable retains its value between function calls
  // where does it reside in program memory (what section)?
  static int counter = 0;
  counter += n;
  return counter;
}
