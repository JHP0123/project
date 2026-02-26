#include "../include/shell.h"
#include <stdlib.h>
#include <stdio.h>

char *buffer = NULL;
size_t size = 0;

int main()
{
    Command *cmd = (Command *)malloc(sizeof(Command));
    (*cmd).argc = 0;    // 초기화 안해주면 random 들어감. argv[argc] = token 에 문제 발생

    printf("argc = %d\n", (*cmd).argc);
    get_command_line(); 
    tokenzie_command(buffer, cmd);
    for(int i = 0; i <= (*cmd).argc; i++)
        printf("argv[%d] = %s\n", i, (*cmd).argv[i]);
    // argv[argc]에는 \0 (NULL)이 있어야 한다.  
    init_command_process(cmd);
    free(buffer);
    free((*cmd).argv);
    free(cmd);
}