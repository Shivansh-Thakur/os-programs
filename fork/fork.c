#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (){
	pid_t pid, pid2;
    printf("before fork...\n");
    pid = fork();        // creates a duplicate process by calling process
                         // On success two processes are created and both run from the next instruction
    if(pid < 0){         // fork failes if it returns < 0
        printf("error");
    }else if(pid == 0){ // child process created, code for child process is written inside here
                        // we can create as many child processes in here
        pid2 = fork();
        if(pid2 == 0){
            printf("I am New child process with id : %d\n", getpid());
            printf("First child's id : %d\n", getppid());
        }else{
            printf("I am child  id : %d\n", getpid());
            printf("My parent's id : %d\n", getppid());
        }
    }else{              // pid > 0, code inside parent process is written here
        printf("I am parent havind id : %d\n", getpid());
        printf("My child's id : %d\n", pid);
    }

    printf("this will be run by both child and parent\n\n");
    return 0;
}
