#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include "../include/shell.h"

void init_command_process(Command *cmd)
{
    pid_t pid;
    pid = fork();
    int status;

    if (pid != 0)   // parent process
    {
        waitpid(pid, &status, 0);
    }
    else            // chile process
    {
        execvp((*cmd).argv[0], (*cmd).argv);
    }
}