/* A C program that reads a variable size array of numbers from the
 * command line and displays the maximum of these.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n; // Number of elements

  // Prompt the user for the number of elements
  printf("How many numbers do you want to enter? ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid input or number of elements.\n");

    // Exit with a error status code
    return 1;
  }

  // Dynamically allocate memory for 'n' doubles
  double *numbers = (double *)malloc(n * sizeof(double));
  if (numbers == NULL) {
    printf("Memory allocation failed.\n");

    // Exit with a error status code
    return 1;
  }

  // Read the numbers from the user
  for (int i = 0; i < n; i++) {
    printf("Enter number %d: ", i + 1);
    if (scanf("%lf", &numbers[i]) != 1) {
      printf("Invalid input.\n");

      // Clean up before exiting
      free(numbers);

      // Exit with a error status code
      return 1;
    }
  }

  // Find the maximum value
  double max = numbers[0];
  for (int i = 1; i < n; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }

  // Display the result
  printf("The maximum number is: %.2f\n", max);

  // Free the allocated memory
  free(numbers);

  // Successful completion
  return 0; 
}
