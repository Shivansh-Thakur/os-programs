#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

int main (){
	int n, fd, f;
	char buffer[50];
	fd = open("seeking", O_RDWR);
	read(fd, buffer, 10);
	write(1, buffer, 10);
	fd = open("seeking",O_RDWR);
	f = lseek(fd, 10, SEEK_CUR);// used to reposition file pointer and return repositioned pointer 
				    // lseek(int fd, off_t offset , int whenc)
				    // where fd is file descriptor of the file you want to read/write
				    // offset is 'where to set the pointer'
				    // whenc is 'from where to set the pointer' using SEEK_SET, SEEK_CUR, SEEK_END
	printf("\ncurrent position is %d\n", f);
	n = read(fd, buffer, 10);
	write(1, buffer, n);
	printf("\nnow from the end\n");
	f = lseek(fd, -11, SEEK_END);
	read(fd, buffer, 10);
	write(1, buffer, 10);
}
