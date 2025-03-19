#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "USAGE: %s <string 1> <string 2>\n", argv[0]);
    return 1;
  }

  char buffer[256];

  memset(buffer, '\0', 256);

  strcat(buffer, argv[1]);
  strcat(buffer, " ");
  strcat(buffer, argv[2]);

  printf("%s\n", buffer);

  return 0;
}
