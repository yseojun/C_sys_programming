#include "csapp.h"

volatile long cnt = 0;

sem_t mutex;

void *thread_fn(void *vargp) {
  long i, niters = *((long *)vargp);
  for (i = 0; i < niters; i++) {
    P(&mutex);
    cnt++;
    V(&mutex);
  }
  return 0;
}

int main(int ac, char **av) {
  long niters;
  pthread_t tid1, tid2;

  Sem_init(&mutex, 0, 1);

  niters = atoi(av[1]);
  Pthread_create(&tid1, NULL, thread_fn, &niters);
  Pthread_create(&tid2, NULL, thread_fn, &niters);

  Pthread_join(tid1, NULL);
  Pthread_join(tid2, NULL);

  if (cnt != (2 * niters))
    printf("Boom! cnt %ld\n", cnt);
  else
    printf("OK cnt %ld\n", cnt);

  exit(0);
}