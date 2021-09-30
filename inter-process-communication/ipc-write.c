#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    FILE *fd;
    char buffer[50];
    sprintf(buffer, "hello world");
    fd = popen("wc -c", "w"); // FILE *popen(const char *command, const char *type)
    fwrite(buffer, sizeof(char), strlen(buffer), fd);
    pclose(fd);
}
