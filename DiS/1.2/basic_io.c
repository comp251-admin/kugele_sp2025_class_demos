/* C input (scanf) example */
#include <stdio.h>

void display_sum(void) {
  int num1, num2;

  // question: what does the ampersand(&) do here?
  printf("Enter a number: ");
  scanf("%d", &num1);

  printf("Enter another: ");
  scanf("%d", &num2);

  printf("%d + %d = %d\n", num1, num2, (num1+num2));
}

void display_value(void) {
  int x;

  // question: What does this do???
  scanf("enter an int:%d", &x);
  printf("x: %d\n", x);
}

int main(void) {

  // display_sum();
  display_value();

  return 0;
}
