#include <stdio.h>

#define MAXLINE 1024

/* Function: readline
 * ------------------
 * Displays prompt and then reads a sequence of characters from 
 * standard input into line until a newline ('\n') or EOF. A 
 * maximum of n characters will be read into line, including a 
 * null terminator ('\0').
 *
 * Returns: line or NULL if EOF
 ****************************************************************/
char* readline(char* line, char* prompt, int n);


int main(void){
  char line[MAXLINE];

  while (readline(line, "$ ", MAXLINE)) {
    printf("read: %s\n", line);
  }

  return 0;
}


char* readline(char* line, char* prompt, int n) {
  fputs(prompt, stdout); // prompt for input

  /* BEGIN CODING */

  line = NULL;

  /* END CODING */

  return line;
}
