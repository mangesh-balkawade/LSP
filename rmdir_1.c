#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    int iRet = rmdir("./data");
    if (iRet == 0)
    {

        printf("directory deleted");
    }
    else
    {
        printf("issue in deletion %s", strerror(errno));
    }
    return 0;
}