#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = 0;
    fd = open("lsp.txt", O_RDONLY);
    printf("Value of fd %d\n", fd);
    if (errno != 0)
    {
        printf("value of error no %d\n", errno);
        printf("error statement %s \n", strerror(errno));
    }
    return 0;
}