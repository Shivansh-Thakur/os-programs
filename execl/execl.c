#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("\n Current process pid = %d will be assigned to ps.\n", getpid());
    execl("/bin/ps", "ps", NULL);// execl will makes a new image of the whole code and run that code
                                 // here in this code it is running ps command's code
    printf("After\n");

    return 0;
}
