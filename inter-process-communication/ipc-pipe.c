#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    pid_t p;
    int fd[2], n;
    char buffer[50];
    
    pipe(fd);
    p = fork(); 
    if(p > 0) { // inside parent
        printf("Reading data from the parent... \n");
        write(fd[1], "hello are you there??\n", 22);
    
    } else if(p == 0) { // inside child
        printf("Writing to a child process...\n");
        n = read(fd[0], buffer, 50);
        write(1, buffer, n);
    
    } else {
        printf("error");
    }
}
