#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * helloWorld( void *str ) {
  printf("Hello. I am thread %ld\n", (long int) pthread_self());
}

int main() {
  pthread_t thid;

  pthread_create (&thid, NULL, helloWorld, NULL);
  printf("Criada thread %ld\n", (long int) thid);

  pthread_join(thid, NULL);
  printf("A thread %ld já terminou\n", (long int) thid);

  return 0;
}
