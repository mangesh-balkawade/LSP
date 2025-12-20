#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 100

int main()
{
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    int fd = open("read_4.c", O_RDONLY);
    if (fd == -1)
    {
        printf("no file is exist");
    }

    int iRet = 1;
    int fd2 = creat("cpy.txt", 0777);
    if (fd2 == -1)
    {
        printf("unable to create file");
    }

    while (iRet != 0)
    {
        iRet = read(fd, buffer, BUFFER_SIZE);
        printf("%d %s", iRet, buffer);
        write(fd2, buffer, BUFFER_SIZE);
        memset(buffer, '\0', BUFFER_SIZE);
    }

    close(fd);
    close(fd2);
    return 0;
}