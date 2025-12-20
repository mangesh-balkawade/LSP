#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    int iRet = symlink("demox.txt", "hello.txt");
    if (iRet == 0)
    {
        printf("sym link created");
    }
    else
    {
        printf("unable to create symb link %s", strerror(errno));
    }
    return 0;
}