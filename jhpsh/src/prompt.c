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
    fflush(stdout);

    read = getline(&buffer, &size, stdin);
    printf("%s", buffer);
    fflush(stdout);

    return buffer;
}

/* printf, stdout, write, fflush, buffer 설명

   - IO 2개의 계층: 
        User Program
           │
           │  stdio library (buffered I/O)
           │  printf, scanf, fgets, getline
           │
           ▼
        Kernel system call (unbuffered I/O)
           read, write
           │
           ▼
        Kernel
           │
           ▼
        File / Terminal / Pipe / Socket
        
   - Buffer를 사용하는 이유
        * 터미널이나 파일에 출력하기 위해서는 write 시스템 콜이 필요하다. 하지만
          write은 context switch가 발생하기 때문에 비용이 비싸다. 그래서 
          보통 printf는 user space에 존재하는 temporary memory space인 buffer를
          사용해서 거기에 저장하다가 buffer가 꽉 차거나 어떠한 조건을 만족하면 
          그때 딱 한번 write을 호출해서 출력한다. 
   - line buffered, block buffered, unbuffered(stderr) 차이와 동작
   - printf 동작과 fflush의 관계
        * fflush는 user buffer에 있는 내용을 바로 출력하는 stdio.h에 정의된 함수이다. 
          내부적으로 write 시스템 콜을 사용한다. 
        * printf("hello");는 fprintf(stdout, "hello", 5);와 동일한 코드. 
          코드를 실행하게 되면 먼저 stdout은 FILE *이므로 FILE 구조체를 가리키니까
          그 구조체로 가서 거기에 있는 user buffer 정보를 통해 buffer에 "hello"를
          저장한다. 
        * 터미널에 출력하는 경우, line buffered로 결정되므로 printf("hello");만 있으면
          buffer에 저장되었다가 프로그램이 종료되었거나 buffer가 꽉 차면 그때 write을 통해
          터미널에 출력한다. 하지만 printf("hello\n");이면 \n을 만나게 되므로 바로 fflush한다. 
          터미널에 출력하지만 printf("hello"); fflush(stdout);처럼 하면 버퍼에 저장되어 있던
          "hello"를 바로 출력한다. 
        * 파일에 출력하는 경우, block buffered로 결정되므로 fflush가 없고 프로그램이 종료되거나
          버퍼가 꽉 차면 그때 파일에 출력한다. 
   - stdout 내부 동작
        * stdout은 stream이고 file 그 자체는 아니지만 FILE *타입이며 
          FILE 구조체로 구현되어 있다(buffer pointer, buffer state).  */

    