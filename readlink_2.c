#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    char path[100];
    memset(path, '\0', sizeof(path));

    int iRet = 0;
    iRet = readlink("./test/lspl.txt", path, sizeof(path));
    if (iRet == -1)
    {
        printf("error occured %s", strerror(errno));
    }
    else
    {
        path[iRet] = '\0';
        printf("path name %s ", path);
    }

    return 0;
}