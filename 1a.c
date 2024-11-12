#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Parent Process (PID: %d)\n", getpid());

    // Creating a child process
    pid = fork();

    if (pid < 0) {
        // fork() failed
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process created (PID: %d)\n", getpid());
        
        // Executing a new program in the child process
        // Here, we're running "ls -l" to list directory contents
        execl("/bin/ls", "ls", "-l", NULL);
        
        // If exec fails
        perror("exec failed");
        return 1;
    }
    else {
        // Parent process waits for the child to complete
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            printf("Child Process terminated with exit status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Child Process did not terminate normally.\n");
        }
        
        printf("Parent Process ending.\n");
    }

    return 0;
}
