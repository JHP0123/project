#include <string.h> // strtok()
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cptr[] = "i like pizza\n";
    // char *cptr로 하면 읽기 전용 메모리가 된다. 하지만 strtok()는 문자열을 수정한다. 
    // strtok()로 인해 "i like pizza\0"는 "i\0like\0pizza\0"로 변형된다. 
    char *token;

    token = strtok(cptr, " ");
    // strtok()는 1) input string을 변형시키고 2) not thread-safe하다. 왜냐하면 내부에 static pointer 하나가 존재하는데
    // 여러 thread가 하나의 static pointer 자원을 사용하려고 하기 때문이다. 

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    token = NULL;

    char *temp_cptr = cptr;
    token = strtok(temp_cptr, " ");
    // strtok()는 1) input string을 변형시키고 2) not thread-safe하다. 왜냐하면 내부에 static pointer 하나가 존재하는데
    // 여러 thread가 하나의 static pointer 자원을 사용하려고 하기 때문이다. 

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }


}