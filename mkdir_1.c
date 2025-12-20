#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    int iRet = mkdir("./data", 0777);
    if (iRet == 0)
    {

        printf("directory created");
    }
    else
    {
        printf("issue in creation");
    }
    return 0;
}