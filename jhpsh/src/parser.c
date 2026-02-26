#include <string.h>
#include <stdlib.h>
#include "../include/shell.h"

Command *tokenzie_command(char *buffer, Command *cmd)
{
    char *token;
    (*cmd).argv = (char **)malloc(sizeof(char *) * 50uL); // argv에 메모리 동적 할당 필요

    token = strtok(buffer, " \n");
    // "ls -ll"를 사용자가 입력하면 buffer = "ls -ll\n\0"을 받게 된다. 
    // execvp는 \n를 포함해서 binary를 찾게 되므로 \n도 같이 없애서 넘겨주어야 한다. 
    (*cmd).argv[(*cmd).argc] = token;
    (*cmd).argc++;
    
    while(token != NULL)
    {
        token = strtok(NULL, " \n");
        (*cmd).argv[(*cmd).argc] = token;
        if (token != NULL)
            (*cmd).argc++;
    }

// ------------------------------------------------------------------------------------

//    (*cmd).argv = (char**)malloc(sizeof(char *) * (size_t)((*cmd).argc + 1));

    return cmd;    // 주소값을 넘겨줘도 없어진다. 
}