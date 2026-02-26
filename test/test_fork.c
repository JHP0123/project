#include <unistd.h>
#include <wait.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    pid = fork();
    // In a shell, we want to run commands in child process, not inside the shell itself
    // Parent shell은 명령문을 받는 shell이고, 받은 명령문을 child process가 실행하는 것이다. 
    // Parent shell은 계속 살아있어야 명령어를 계속 받아야 한다(loop).

    if (pid != 0)
    {
        wait(NULL);
        printf("Parent Process\n");
    }
    else
        printf("Child Process\n");
}