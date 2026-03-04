#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/shell.h"

void jhpsh_loop(void)
{
    Command *cmd = (Command *)malloc(sizeof(Command));
    (*cmd).argv = (char **)malloc(sizeof(char *) * 50uL); // argv에 메모리 동적 할당 필요
    (*cmd).argc = 0;    // 초기화 안해주면 random 들어감. argv[argc] = token 에 문제 발생

    printf("argc = %d\n", (*cmd).argc);
    while (1)
    {
        (*cmd).argc = 0;
        get_command_line(); 
        if ((strcmp(buffer, "-\n") == 0) || (strcmp(buffer, "exit\n") == 0)) // "-\n"를 입력하면 loop 탈출
            break;
        tokenzie_command(buffer, cmd);

        if (strcmp((*cmd).argv[0], "cd") == 0)
        {
            /* handle cd command */
            cd_command((*cmd).argv[1]);
            continue;
        }
        // else if (strcmp((*cmd).argv[0], "exit") == 0)
        // {
        //     break;
        //     /* handle exit command */
        // }
        else if (strcmp((*cmd).argv[0], "echo") == 0)
        {
            /* handle echo command */
        }

        for(int i = 0; i <= (*cmd).argc; i++)
            printf("argv[%d] = %s\n", i, (*cmd).argv[i]);
        // argv[argc]에는 \0 (NULL)이 있어야 한다.  
        init_command_process(cmd);
    }

        m_dealloc(buffer, (*cmd).argv, cmd);
        // free(buffer);
        // free((*cmd).argv);
        // free(cmd);
}