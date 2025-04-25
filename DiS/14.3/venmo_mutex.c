#include <pthread.h>
#include <stdio.h>

#define NUM_ITERATIONS 100000 // number of operations for each thread

// shared Venmo balance
int venmo_balance = 1000;

pthread_mutex_t mutex;

void *deposit(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; ++i) {
    pthread_mutex_lock(&mutex);

    /* BEGIN CRITICAL SECTION */
    venmo_balance += 100; // deposit $100
    /* END CRITICAL SECTION */

    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void *withdraw(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; ++i) {
    pthread_mutex_lock(&mutex);

    /* BEGIN CRITICAL SECTION */
    venmo_balance -= 100; // withdraw $100
    /* END CRITICAL SECTION */

    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

int main() {
  pthread_t thread_a, thread_b;

  pthread_mutex_init(&mutex, NULL);

  pthread_create(&thread_a, NULL, deposit, NULL);
  pthread_create(&thread_b, NULL, withdraw, NULL);

  pthread_join(thread_a, NULL);
  pthread_join(thread_b, NULL);

  printf("Final venmo balance: $%d\n", venmo_balance);

  pthread_mutex_destroy(&mutex);

  return 0;
}
