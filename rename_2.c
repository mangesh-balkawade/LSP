#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main()
{
    char arr[] = "./demo.tx";
    int iRet = rename(arr, "./december.txt");
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