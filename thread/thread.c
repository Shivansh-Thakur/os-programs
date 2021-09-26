// use "gcc program_name.c -lpthread" to compile the code
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);
int i, j;

int main(void)
{
    pthread_t a_thread;// thread declaration
    pthread_create(&a_thread, NULL, thread_function, NULL); // function to create a thread
                                                            /* In the pthread_create(&a_thread, NULL, thread_function, NULL)
                                                            first argument : stores id of thread
                                                            second argument : default arguments
                                                            third parameter : thread_function that performs all the tasks that a thread is supposed to do
                                                            fourth parameter : arguments to this thread_function */
    pthread_join(a_thread, NULL);// process wait for the thread to finish
                                /* In the function pthread_join(a_thread, NULL)
                                first argument : name of the thread
                                second argument : variable that stores result returned by the thread
                                */
    printf("In the main process : \n");
    for(i = 10; i < 15; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return 0;
}

void *thread_function(void *arg)// work to be done by the thread
{
    printf("Inside thread : \n");
    for(j = 0; j < 5; j++) {
        printf("%d\n", j);
        sleep(1);
    }
}
