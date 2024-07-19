#include <stdio.h>
#include <pthread.h>
#include<dos.h>

void *printNumber(void *arg)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("thread 1: %d \n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *printLetter(void *arg)
{
    int i;
    char letters[] = {'a', 'b', 'c', 'd', 'e'};
    for (i = 0; i < 5; i++)
    {
        printf("thread 2: %c \n", letters[i]);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main()
{
	printf("Nabin Thapa \n\n");
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, printNumber, NULL);
    pthread_create(&thread2, NULL, printLetter, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

