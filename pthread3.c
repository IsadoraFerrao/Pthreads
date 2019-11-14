#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int buffer = 0;
pthread_mutex_t m;
pthread_cond_t c;

void *produtor(void *str) {
  int i, a;
  for(i=0; i<100; i++) {
    pthread_mutex_lock(&m);
    buffer++;
	printf("%d\n", buffer);
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&m);
  }
}

void *consumidor(void *str) {
  int i, b;
  for (i=0; i<100; i++) {
    pthread_mutex_lock(&m);
    while(buffer <= 0)
      pthread_cond_wait(&c, &m);
    buffer--;
	printf("%d\n", buffer);
    pthread_mutex_unlock(&m);
  }
}

int main() {
  pthread_t thid1, thid2;
  pthread_mutex_init(&m, NULL);
  pthread_cond_init(&c, NULL);
  
  pthread_create (&thid1, NULL, produtor, NULL);
  pthread_create (&thid2, NULL, consumidor, NULL);

  pthread_join(thid1, NULL);
  pthread_join(thid2, NULL);
  return 0;
}



