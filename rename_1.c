#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main()
{
    char arr[] = "demox.txt";
    int iRet = rename(arr, "demo.tx");
    if (iRet == 0)
    {
        printf("file renamed");
    }
    else
    {
        printf("error in file %s", strerror(errno));
        return -1;
    }
    return 0;
}