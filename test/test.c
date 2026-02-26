#include <string.h>
#include <stdio.h>

int main()
{
    char ch[] = "i like pizza\n";
    char space[] = " ";
    char *ptr = NULL;

    ptr = strstr(ch, space);
    printf("%p\n", ch);
    printf("%p\n", ptr);
}