#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    int fd = 0;
    fd = open("./text/lspl.txt", O_RDONLY); // issue
    if (fd == -1)
    {
        printf("unable to open file %s", strerror(errno));
        return -1;
    }
    else
    {
        printf("file opened");
        close(fd);
    }
    return 0;
}