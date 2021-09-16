#include <unistd.h>
#include <stdio.h>

int main (void)
{
	int n;
	char buffer[30];
//	printf("Enter something to read data into a char array");
	n = read(1, buffer, 30); // returns total number of characters read
	write(1, buffer, n);
	return 0;
}
