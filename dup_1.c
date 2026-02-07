#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd1 = 0, fd2 = 0;

    fd1 = open("./LSP.txt",O_RDWR);
    printf("fd1 : %d\n",fd1);   // 3

    fd2 = dup(fd1);
    printf("fd2 : %d\n",fd2);   // 4

    return 0;
}