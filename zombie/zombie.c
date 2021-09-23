#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main ()
{
	pid_t pid, pid2, parent_id;
    printf("before fork...\n");
    pid = fork();

    if(pid < 0){
        printf("error");

    } else if(pid == 0) {
            printf("I am child  id : %d\n", getpid());
            printf("My parent's id : %d\n", getppid());
        
    } else {
        sleep(5); //It makes the child process to finish its work without being terminated 
        //and thus parent process never erases its child's entries 
        // and child process become a zombie process (indicated by <defunct> in the terminal)
        // thus we use wait(NULL) as it wait for the child to terminate its state
        printf("I am parent havind id : %d\n", getpid());
        printf("My child's id : %d\n", pid);
    }

    return 0;
}
