#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (){
	int n, fd, fd1; // always fd > 2
	char buffer[50];
	fd = open("test.txt", O_RDONLY); // opens or possibly create a new file and return file descriptor whose value is always greter than 2 
	                                // as 0, 1, 2 are already used for some other purpose
	// open(const char* pathname, int flag) for creating 
	// open(const char* pathname, int flag, int mode)
	n = read(fd, buffer, 10);
	write(1, buffer, n);
	return 0;
}
