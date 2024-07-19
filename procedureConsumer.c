#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>

#define BufferSize 5

sem_t empty;
sem_t full;
int in=0;
int out=0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *pnum)
{
	int item,i;
	while(1){
		item=rand()%100;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in]=item;
		printf("Producer %d: Insert item %d at %d\n",*((int *)pnum),buffer[in],in);
		in=(in+1)%BufferSize;
		sleep(1);
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}
void *consumer(void *cnum)
{
	int i;
	while(1){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item=buffer[out];
		printf("Consumer %d: Delete item %d at %d\n",*((int *)cnum),buffer[out],out);
		out=(out+1)%BufferSize;
		sleep(1);
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}
int main()
{
	pthread_t pro[3],con[3];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,BufferSize);
	sem_init(&full,0,0);
	int a[3]={1,2,3};
	int i;
	printf("\n\t Nabin Thapa\n\n");
	for(i=0;i<3;i++)
		pthread_create(&pro[i],NULL,(void *)producer,(void *)&a[i]);
	for(i=0;i<3;i++)
		pthread_create(&con[i],NULL,(void *)consumer,(void *)&a[i]);
	for(i=0;i<3;i++)
		pthread_join(pro[i],NULL);
	for(i=0;i<3;i++)	
		pthread_join(con[i],NULL);
		
	getch();
	return 0;
}
