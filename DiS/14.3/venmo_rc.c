#include <pthread.h>
#include <stdio.h>

#define NUM_ITERATIONS 100000 // number of operations for each thread

// shared Venmo balance
int venmo_balance = 1000;

void *deposit(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; ++i) {
    venmo_balance += 100; // deposit $100
  }
  return NULL;
}

void *withdraw(void *arg) {
  for (int i = 0; i < NUM_ITERATIONS; ++i) {
    venmo_balance -= 100; // withdraw $100
  }
  return NULL;
}

int main() {
  pthread_t thread_a, thread_b;

  pthread_create(&thread_a, NULL, deposit, NULL);
  pthread_create(&thread_b, NULL, withdraw, NULL);

  pthread_join(thread_a, NULL);
  pthread_join(thread_b, NULL);

  printf("Final Venmo balance: $%d\n", venmo_balance);

  return 0;
}
