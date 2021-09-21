// if you have multiple child process and you want to wait for a
// perticular process then you can use waitpid()
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
	pid_t pid, pid2;
    printf("before fork...\n");
    pid = fork();

    if(pid < 0){// fork failed
        printf("error");

    } else if(pid == 0) {
        pid2 = fork();
        if(pid2 == 0){
            //sleep(1);// sleep or pause this process for 1 sec and let the parent finish its job first
            printf("I am New child process with id : %d\n", getpid());
            printf("First child's id : %d\n", getppid());
        }else{
            //sleep(2);
            printf("I am child  id : %d\n", getpid());
            printf("My parent's id : %d\n", getppid());
        }

    } else {
        waitpid(pid, NULL, 0);// makes the parent to wait for the child with specified pid to change its state
        printf("I am parent havind id : %d\n", getpid());
        printf("My child's id : %d\n", pid);
    }

    printf("this will be run by both child and parent\n\n");
    return 0;
}
