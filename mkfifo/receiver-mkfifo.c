#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int res, n;
    char buffer[100];
    res = open("fifo1", O_RDONLY);
    //res = open("fifo1", O_NONBLOCK, O_RDONLY); //for non blocked mode
    n = read(res, buffer, 100);
    printf("Reader processs having pid %d has started\n", getpid());
    printf("Data received by the receiver %d is : %s\n", getpid(), buffer);
}
