#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
	pid_t pid, pid2, parent_id;
    printf("\nbefore fork...\n");
    pid = fork();

    if(pid < 0){
        printf("error");

    } else if(pid == 0) {
            sleep(10);// parent process terminates and makes the child as orphone process
            printf("\n\nAfter 10 sec of sleep child process does not recognize its parent's id as it was terminated\n");
            printf("I am child  id : %d\n", getpid());
            printf("My parent's id : %d\n", getppid());
        
    } else {
        sleep(3);// use ps command twice, one before 3 seconds of running the code in terminal as background process(./a.out &) and
                 // one after 3 seconds, to verify that parent process has terminated and it's child is now an orphan process.
        printf("\nI am parent havind id : %d\n", getpid());
        printf("My child's id : %d\n", pid);
    }

    return 0;
}
