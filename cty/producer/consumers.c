#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <sys/types.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <string.h> 
#include <unistd.h> 

#define BUFFER_SIZE 5 
typedef int buffer_item;

sem_t empty, full, mutex;
buffer_item buffer[BUFFER_SIZE];
int in, out;
struct data {
    int id;
    int opTime;
    int lastTime;
    int productId;
};
int insert_item(buffer_item item) { 
/* insert item into buffer */ 
buffer[out] = item; 
out = (out + 1) % BUFFER_SIZE; 
return 0; 
}
int remove_item(buffer_item *item) {
	*item = buffer[in];
	in = (in + 1) % BUFFER_SIZE;
	 return 0;   
}
void *producer(void* param) { 
int productId = ((struct data*)param)->productId; 
int lastTime = ((struct data*)param)->lastTime; 
int opTime = ((struct data*)param)->opTime; 
int id = ((struct data*)param)->id;
free(param);
sleep(opTime);
sem_wait(&empty);
sem_wait(&mutex);

insert_item(productId);
sleep(lastTime);
printf("Thread %d: Producer produce %d\n", id, productId);

    sem_post(&mutex);
    sem_post(&full);
  pthread_exit(0);
}


