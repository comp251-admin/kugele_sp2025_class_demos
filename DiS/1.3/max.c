/* C if-else example */
#include <stdio.h>

/* find the maximum of two integers */
int find_max(int num1, int num2) {
  int max;

  if (num1 > num2) {
    max = num1;
  }
  else {
    max = num2;
  }

  return max;
}

int main(void) {
  int num1, num2;

  // read values from terminal
  printf("Enter the 1st number: ");
  scanf("%d", &num1);
  printf("Enter the 2nd number: ");
  scanf("%d", &num2);

  // display the largest of the two values
  int max = find_max(num1, num2);
  printf("%d is biggest\n", max);

  return 0;
}
