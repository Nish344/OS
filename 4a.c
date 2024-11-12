#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[1024] = "Hello BIT";
    char *myfifo = "/home/nishanth_antony/clg_prgms/os";

    // Create the FIFO (named pipe) with read/write permissions
    mkfifo(myfifo, 0666);

    printf("Run Reader process to read the FIFO File\n");

    // Open the FIFO for writing and write the buffer data
    fd = open(myfifo, O_WRONLY);
    write(fd, buf, sizeof(buf));

    // Close the file descriptor and remove the FIFO
    close(fd);
    unlink(myfifo); // remove the FIFO

    return 0;
}
