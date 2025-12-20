#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    struct stat sobj;
    int iRet = stat("lsp.txt", &sobj);
    if (iRet == 0)
    {
        printf("stat works");
    }
    else
    {
        printf("stats not working");
        return -1;
    }
    return 0;
}