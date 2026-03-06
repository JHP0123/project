#include <unistd.h> // chdir(char *path)
#include <string.h>
#include <stdio.h>

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

void echo_command(char *buffer, const char *delim_str_type, Command *cmd)
{
    char *sStr = buffer;
    char *string = NULL;
    int set_string_lock = 0;
    int exclam_lock = 0;
    int buffer_size = strlen(buffer);
    int delim_size = strlen(delim_str_type);

    for (int i = 0; i <= buffer_size; i++)
    {
        if (buffer[i] == '"')
        {
            exclam_lock++;
        }

        if (exclam_lock % 2 == 0)
        {
            for (int j = 0; j < delim_size; j++)
            {
                if (buffer[i] == delim_str_type[j])
                {
                    buffer[i] = '\0';

                    (*cmd).argv[(*cmd).argc] = sStr;
                    (*cmd).argc++;
                    sStr = &buffer[i + 1];
                } 
            }

            if (set_string_lock == 1)
                set_string_lock--;
        }

        else if (exclam_lock % 2 == 1)
        {
            if (set_string_lock == 0)
            {
                string = &buffer[i];
                set_string_lock++;
            }
            continue;
        }

        // else if (exclam_lock == 2)
        // {
        //     (*cmd).argv[(*cmd).argc] = sStr;
        //     exclam_lock++;  // exclam_lock = 3
        // }
    }

    (*cmd).argv[(*cmd).argc] = NULL;

    if (string != NULL)
        printf("%s\n", string);
    else
    {
        for (int cnt = 1; cnt < (*cmd).argc; cnt++)
        {
            printf("%s ", (*cmd).argv[cnt]);
        }
    }
    printf("\n");
    fflush(stdout);
}