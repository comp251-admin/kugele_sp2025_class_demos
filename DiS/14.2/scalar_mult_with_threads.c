#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Struct to bundle all arguments for each thread */
struct t_arg {
  double *array;   // pointer to the shared array
  long length;     // total number of elements in the array
  double s;        // scaling factor
  long numthreads; // total number of threads
  long id;         // this thread's logical ID (0..numthreads-1)
};

/* Thread function: multiply array slice by s */
void *scalar_multiply(void *args) {
  struct t_arg *myargs = (struct t_arg *)args;
  long id = myargs->id;
  long length = myargs->length;
  double s = myargs->s;
  long nthreads = myargs->numthreads;
  double *ap = myargs->array; // alias for the array pointer

  /* Compute chunk boundaries for this thread */
  long chunk = length / nthreads;
  long start = id * chunk;
  long end = start + chunk;
  if (id == nthreads - 1) {
    /* Last thread handles any remainder */
    end = length;
  }

  /* Perform the scalar multiplication */
  for (long i = start; i < end; i++) {
    ap[i] *= s;
  }

  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <nthreads> <length> <scalar>\n", argv[0]);
    return EXIT_FAILURE;
  }

  /* Parse command-line arguments */
  char *endptr;
  long nthreads = strtol(argv[1], NULL, 10);
  long length = strtol(argv[2], NULL, 10);
  double s = strtod(argv[3], &endptr);

  /* Allocate and initialize the shared array */
  double *array = malloc(length * sizeof(double));
  if (array == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }
  for (long i = 0; i < length; i++) {
    array[i] = (double)i; /* example initialization */
  }

  /* Allocate thread handles and argument structs */
  pthread_t *threads = malloc(nthreads * sizeof(pthread_t));
  struct t_arg *thread_args = malloc(nthreads * sizeof(struct t_arg));
  if (threads == NULL || thread_args == NULL) {
    perror("malloc");
    free(array);
    return EXIT_FAILURE;
  }

  /* Populate each thread's argument record */
  for (long i = 0; i < nthreads; i++) {
    thread_args[i].array = array;
    thread_args[i].length = length;
    thread_args[i].s = s;
    thread_args[i].numthreads = nthreads;
    thread_args[i].id = i;
  }

  /* Start timing */
  struct timespec t_start, t_end;
  if (clock_gettime(CLOCK_MONOTONIC, &t_start) != 0) {
    perror("clock_gettime");
    return EXIT_FAILURE;
  }

  /* Create all threads */
  for (long i = 0; i < nthreads; i++) {
    int rc =
        pthread_create(&threads[i], NULL, scalar_multiply, &thread_args[i]);
    if (rc != 0) {
      fprintf(stderr, "Error: pthread_create failed for thread %ld\n", i);
      free(array);
      free(threads);
      free(thread_args);
      return EXIT_FAILURE;
    }
  }

  /* Join all threads */
  for (long i = 0; i < nthreads; i++) {
    pthread_join(threads[i], NULL);
  }

  /* Stop timing */
  if (clock_gettime(CLOCK_MONOTONIC, &t_end) != 0) {
    perror("clock_gettime");
    return EXIT_FAILURE;
  }

  /* Compute elapsed time in seconds */
  double elapsed =
      (t_end.tv_sec - t_start.tv_sec) + (t_end.tv_nsec - t_start.tv_nsec) / 1e9;

  /* (Optional) Verify a few entries */
  printf("array[0] = %f\n", array[0]);
  printf("array[%ld] = %f\n", length / 2, array[length / 2]);
  printf("array[%ld] = %f\n", length - 1, array[length - 1]);

  printf("\n");
  printf("**********************************\n");
  printf("* Elapsed time: %.6f seconds *\n", elapsed);
  printf("**********************************\n");

  /* Clean up */
  free(array);
  free(threads);
  free(thread_args);

  return EXIT_SUCCESS;
}
