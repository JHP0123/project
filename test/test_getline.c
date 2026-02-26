#define _GNU_SOURCE     // getline()
#include <stdio.h>      // printf()
#include <stdlib.h>     // free()
#include <stddef.h>     // size_t, ssize_t (signed size_t)

int main()
{
    char *buffer = NULL;
    size_t size = 0;

    ssize_t read = getline(&buffer, &size, stdin);
    // ssize_t getline(char **lineptr, size_t *n, FILE *stream)
    // lineptr: Pointer to a char *buffer(may be NULL - memory will be allocated dynamically)
    // n      : Pointer to size of the buffer (can be 0 if lineptr is NULL)
    // stream : Input stream (usually stdin)
    // Returns number of character read (including newline), or -1 on failure or EOF

    // Because user usually inputs undefined length of command on a shell, 
    // getline() dynamically allocates memory.

    // free() is needed to deallocate the memory allocated to lineptr.
    if (read == -1)
    {
        return 0;
    }

    printf("LINE: %s", buffer);
    printf("%ld bytes read\n", read);

    free((void *)buffer);

}