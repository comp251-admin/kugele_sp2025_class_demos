#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) {
  if (argc < 2) {
    fprintf(stderr, "usage: %s <executable> [args...]\n", argv[0]);
    return 1;
  }

  int status;
  pid_t pid = fork();

  // why are we allocating space for argc and not argc - 1 elements
  char **new_argv = malloc(sizeof(char *) * argc);
  if (new_argv == NULL) {
    perror("malloc failed");
    return 1;
  }

  // loop over arguments (must be at least one - prog. executable)
  for (int i = 1; i < argc; i++) {
    new_argv[i - 1] = argv[i];
  }

  // add required NULL after command line arguments
  new_argv[argc - 1] = NULL;

  // error handling
  if (pid == -1) {
    perror("fork failed");
    free(new_argv);
    return 1;
  }

  // child process
  else if (pid == 0) {
    // replace child's program image with new image
    if (execve(new_argv[0], new_argv, envp) == -1) { /* error handling */
      perror("execve failed");
      free(new_argv);
      return 1;
    }

    // impossible to get here... why?
  }

  // parent process
  else {
    wait(&status); /* get status code and allow OS to reap the child process */
    printf("child exited with status: %d\n", status);
  }

  free(new_argv);
  return 0;
}
