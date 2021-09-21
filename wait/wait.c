#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t p;
    int w1, wstatus;

    p = fork();
    if(p == 0) {
        printf("I am child with id %d \n", getpid());
        printf("My parents id is %d \n", getppid());
    
    } else {
        //wait(NULL);   if you are not concerned with wait status, use it. 
        //It will change the state of child process to terminate state.
        w1 = wait(&wstatus); // wait system call makes parent process to wait for the child 
                            // process to terminate, therefore always use it in parent process.
        printf("Child process status is %d, i.e, terminated\n", WIFEXITED(wstatus));
        printf("Child process which is terminated is %d\n", w1);
        printf("I am parent with id %d\n", getpid());
        printf("My child's id is %d\n", p);
    }
    return 0;
}
