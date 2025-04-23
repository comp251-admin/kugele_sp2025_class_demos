#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

int g_count = 0;

void *add_one(void *arg) {
  g_count++;
  return NULL;
}

int main(void) {
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, add_one, NULL);
  pthread_create(&thread2, NULL, add_one, NULL);

  printf("in main [pid: %d] %d\n", getpid(), g_count);

  add_one(NULL);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("in main [pid: %d] %d\n", getpid(), g_count);

  return 0;
}
