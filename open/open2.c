#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main (){
	int n , fd, fd1;
	char buffer[100];
	//fd = open("test.txt", O_RDONLY);
	//n = read(fd, buffer, 100);
	printf("Type content into the target file here \n");
	n = read(0, buffer, 100);
	fd1 = open("target", O_WRONLY | O_APPEND, 0642); // override file 
	write(fd1, buffer, n);
	printf("\nConten you typed has now written into the 'target' file :)");
	return 0;
}
