#include <unistd.h> // execvp()
#include <wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
// argc     : at least 1. Always includes the name of the name of the executable program itself as the first argument
// argv[]   : Argument vector is an array of character pointers
{
    pid_t pid;
    pid = fork();
    int status;
    
    if (pid != 0)
    {
        wait(&status);
    }
    else
        execvp(argv[0], argv);
        // int execvp(const char *file, char *const argv[])
        // file     : Name of the program to run (e.g., "ls")
        // argv[]   : Argument list - first element is the command name, the last is NULL
        // Only returns on failure (returns -1), because if successful, the current process is replaced

        // execvp() searches for the binary in the PATH
}