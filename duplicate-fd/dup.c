#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main (){
	int n, fd, f, f2;
	char buffer[50];
	fd = open("duplicate", O_RDWR); 
    printf("current file discriptor is %d\n", fd);
    f = dup(fd); // dup(old file descriptor)
    printf("duplicate file discriptor using dup is %d\n", f);
    f2 = dup2(f, 7); // dup(old file descriptor, new file descriptor)
    printf("new duplicate file discriptor is %d\n", f2);
    printf("fd = %d f = %d f2 = %d\n", fd, f, f2);
}
