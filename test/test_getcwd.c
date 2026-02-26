#include <stdlib.h> // NULL
#include <unistd.h> // getcwd() 
#include <stdio.h>  // printf()

int main()
{
    char buffer[100];

    getcwd(buffer, 100);
    // get current working directory
    
    printf("%s\n", buffer);
}