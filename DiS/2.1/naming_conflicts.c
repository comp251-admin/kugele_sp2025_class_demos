#include <stdio.h>

int x = 1; /* global x */

int main(void) {
    printf("x (before declared locally): %d\n", x);

    int x = 7;   /* local x */

    printf("x (after declared locally): %d\n", x);

    {
      extern int x;
      printf("x (using extern in nested scope): %d\n", x);
    }

    printf("x (after nested scope): %d\n", x);

    return 0;
}
