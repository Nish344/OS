#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_BUF 1024

void main()
{
    int fd;
    char *myfifo = "/home/nishanth_antony/clg_prgms/os";
    char buf[MAX_BUF];

    // Open the FIFO for reading
    fd = open(myfifo, O_RDONLY);

    // Read data from the FIFO into the buffer
    read(fd, buf, MAX_BUF);

    printf("Reader process has read: %s\n", buf);

    // Close the file descriptor
    close(fd);

    
}
