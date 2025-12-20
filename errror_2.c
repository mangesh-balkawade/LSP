#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
    int fd = 0;
    fd = open("marvellous.txt", O_RDONLY);
    printf("Value of fd %d\n", fd);
    printf("value of errorno %d\n", errno);
    return 0;
}