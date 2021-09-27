#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fun1(void *arg);
void *fun2(void *arg);
int shared = 1;

int main(void)
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("New value of shared variable is %d \n", shared);

    return 0;
}

void *fun1(void *arg)
{
    int x = shared;
    printf("thread1 reads the shared variable \n");
    x++;
    printf("local value being incremented by fun1 is %d\n", x);
    sleep(1);// pre-emtes the thread 1
    shared = x;
    printf("Value of shared variable updated by thread 1 is %d\n", shared);
}

void *fun2(void *arg)
{
    int x = shared;
    printf("thread2 reads the shared variable \n");
    x--;
    printf("local value being dectremented by fun2 is %d\n", x);
    sleep(1);// pre-emtes the thread 2
    shared = x;
    printf("Value of shared variable updated by thread 2 is %d\n", shared);
}
