#include <stdio.h>

/*
 * Function Prototypes
 *
 */
int max(int x, int y);
void print_table(void);

// main function (always required)
int main(void) {
	int func_to_call = -1;

  puts("Function to call? (1=max, 2=print_table)");
	scanf("%d", &func_to_call);

	if (func_to_call == 1) {
		int num1, num2;

		printf("num1: ");
		scanf("%d", &num1);
		printf("num2: ");
		scanf("%d", &num2);

    // question: why were we able to call max here before it is defined?
		printf("max: %d\n", max(num1, num2));	
	}
	else if (func_to_call == 2) {
		print_table();
	}
	else {
		printf("invalid choice: %d\n", func_to_call);
	}

	return 0;
}

/*
 * Function Definitions
 *
 */
int max(int x, int y) {
	int bigger;

	bigger = x;
	if (y > x) {
		bigger = y;
	}

	return bigger;
}

void print_table(void) {
	int start, stop;

	printf("start: ");
	scanf("%d", &start);
	printf("stop: ");
	scanf("%d", &stop);

	int i;

	for (i = start; i <= stop; i++) {
		printf("%d\t", i*i);
	}

	printf("\n");
}
