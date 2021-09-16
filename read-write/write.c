#include <unistd.h>
#include <stdio.h>
int main (void) 
{
    int n = write(1, "hello\n", 6);  
    // write(file descriptor, buffer, count) returns number of characters written
    // FILE DESCRIPTORS = [0 for input device ,1 for output device, 2 for error shown on output device]
    // COUNT refer to the string length upto which you want to write
    printf("%d number of characters are written.", n);
    return 0;
}
