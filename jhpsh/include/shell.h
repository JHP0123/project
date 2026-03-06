#ifndef SHELL_H
#define SHELL_H
/* Header file is for interface declaration. 
   Only common delcarations are in the header file.

   ** Core Principles **
      - #include usually are in the .c file where we use them directly
      - Struct, function prototype, common macros included in the header file
      
   Try to keep header files clean and simple. */

#include <stddef.h>
#include <sys/types.h>

typedef struct
{
    char **argv;
    int argc;
} Command;

extern char *buffer;    // Do not define variables in the header file. 
extern size_t size;     // Multiple definition linking error will be caused.
                        // extern: Does not allocate memory, but is a declaration
                        //         that the variables will be used somewhere.
                        // buffer, size is defined in prompt.c

// Output current working directory and gets the input command line
char *get_command_line(void);   // prompt.c

// Tokenize command input string
Command *tokenzie_command(char *buffer, Command *cmd); // parser.c

// Process create/execute/wait
void init_command_process(Command *cmd); // execute.c

// Deallocation routine
void m_dealloc(char *buffer, char **argv, Command *cmd); // memory.c

// Loop jhpsh
void jhpsh_loop(void);  // jhpsh_loop.c

//Built-ins command (cd, exit, echo)
void cd_command(char *dir);   // built-ins.c
void echo_command(char *buffer, const char *delim_str_type, Command *cmd);

#endif