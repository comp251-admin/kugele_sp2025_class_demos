#include <stdio.h>
#include <stdlib.h>

#define WITH_LEADING_ZEROS 0
#define WITHOUT_LEADING_ZEROS 0

/* function prototypes */
void print_binary(int num, int leading_zeros);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <integer> <mask>\n", argv[0]);
    return 1;
  }

  int num = atoi(argv[1]);
  int mask = atoi(argv[2]);

  printf("\nbitwise AND (num & mask)\n");
  print_binary(num, WITH_LEADING_ZEROS);
  puts(" (num)");
  print_binary(mask, WITH_LEADING_ZEROS);
  puts(" (mask)");
  puts("--------------------------------");
  print_binary(num & mask, WITH_LEADING_ZEROS);
  putchar('\n');

  /*
  printf("\nbitwise OR (num | mask)\n");
  print_binary(num, WITH_LEADING_ZEROS);
  puts(" (num)");
  print_binary(mask, WITH_LEADING_ZEROS);
  puts(" (mask)");
  puts("--------------------------------");
  print_binary(num | mask, WITH_LEADING_ZEROS);
  putchar('\n');

  printf("\nbitwise NOT (~num)\n");
  print_binary(num, WITH_LEADING_ZEROS);
  puts(" (num)");
  puts("--------------------------------");
  print_binary(~num, WITH_LEADING_ZEROS);
  putchar('\n');
  */

  return 0;
}

void print_binary(int num, int leading_zeros) {
  unsigned int mask = 1 << (sizeof(int) * 8 - 1);

  for (; mask > 0; mask >>= 1) {
    if (num & mask) {
      leading_zeros = 0;
      putchar('1');
    } else if (!leading_zeros) {
      putchar('0');
    }
  }

  if (leading_zeros) {
    putchar('0');
  }
}
