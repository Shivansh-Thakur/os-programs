#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    FILE *fd;
    char buffer[50];
    fd = popen("ls", "r"); // FILE *popen(const char *command, const char *type)
    fread(buffer, sizeof(char), 12, fd);
    write(1, buffer, 12); 
    printf("\n");
    pclose(fd);
}
