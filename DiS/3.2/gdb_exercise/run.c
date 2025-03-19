#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "secrets.h"
#include "util.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <user id> <password>\n", argv[0]);
    return 1;
  }

  char *id = argv[1];
  char *password = argv[2];

  startMachine(id);

  if (validatePassword(password)) {
    revealSecrets();
  } else {
    selfDestruct();
  }

  return 0;
}
