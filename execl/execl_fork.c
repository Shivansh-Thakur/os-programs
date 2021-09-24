#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int pid;
    pid = fork();
    
    if(pid < 0){
        printf("error");

    }else if(pid == 0){
        printf("I am child with id %d\n", getpid());
        printf("pid %d will be assigned to ps command and no instruction will run after execl\n", getpid());
        execl("/bin/ps", "ps", NULL);// execl will make a new image of the whole code and run that code
                                    // here in this code it is running ps command's code.
        printf("My parent's id is %d\n", getppid());

    }else{
        wait(NULL);
        printf("I am parent with id %d\n", getpid());
        printf("My child's id is %d\n", pid);
    }
   
    return 0;
}
