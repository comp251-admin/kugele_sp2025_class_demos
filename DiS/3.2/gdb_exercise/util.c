#include "util.h"
#include "secrets.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decode_rot13(const char *input) {
  size_t len = strlen(input);

  char *decoded = malloc(len + 1);
  if (!decoded) {
    perror("malloc failed");
    exit(1);
  }

  for (size_t i = 0; i < len; i++) {
    char c = input[i];
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      decoded[i] = (c - base + 13) % 26 + base;
    } else {
      decoded[i] = c;
    }
  }

  decoded[len] = '\0';
  return decoded;
}

int validatePassword(const char *password) {
  int r;
  const char *k = NULL;

  do {
    r = rand() % 1000000000 + 1;
    k = *(cipher_block + r % MAX);
  } while (k[0] != 112);

  return !strcmp(password, decode_rot13(k));
}
