#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 100

int main()
{
    char buffer[BUFFER_SIZE];
    int fd = open("lsp.txt", O_RDWR);
    if (fd < 0)
    {
        printf("Wrong file name");
    }
    int iRet = read(fd, buffer, BUFFER_SIZE);
    if (iRet > 0)
    {
        printf("data from file %s", buffer);
    }

    return 0;
}