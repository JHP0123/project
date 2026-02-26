// #include "/home/jhparkk1023/project/jhpsh/include/shell.h"
#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include "../include/shell.h"

char *get_command_line(void)
{
    char cwd[50];
    ssize_t read = 0;

    getcwd(cwd, 50);
    printf("%s>> ", cwd);

    read = getline(&buffer, &size, stdin);
    printf("%s", buffer);

    return buffer;
}