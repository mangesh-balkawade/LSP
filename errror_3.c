#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = 0;
    fd = open("marvellous.txt", O_RDONLY);
    printf("Value of fd %d\n", fd);
    printf("value of error no %d\n", errno);
    printf("error statement %s \n", strerror(errno));
    return 0;
}