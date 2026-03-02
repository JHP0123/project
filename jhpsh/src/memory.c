#include <stdlib.h>

#include "../include/shell.h"

void m_dealloc(char *buffer, char **argv, Command *cmd)
{
    free(buffer);
    free(argv);
    free(cmd);
}