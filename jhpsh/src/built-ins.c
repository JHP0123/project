#include <unistd.h> // chdir(char *path)
#include <string.h>
#include "../include/shell.h"

void cd_command(char *dir)
{
    char *home_dir = "/home";
    if (strcmp(dir, "~") == 0)  // cd ~인 경우
    {
        chdir(home_dir);
    }
    else if (strncmp(dir, "~", 1) == 0)
    {
        chdir(home_dir);
        chdir(dir + 2);
    }
    else
        chdir(dir);
}