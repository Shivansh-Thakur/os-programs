#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int res;
    res = open("fifo1", O_WRONLY);
    //res = open("fifo1",O_NONBLOCK, O_WRONLY);  //for non blocked mode
    write(res, "message", 7);
    printf("Sender processs having pid %d sent the data\n", getpid());
}
