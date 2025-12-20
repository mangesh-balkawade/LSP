#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int iRet = link("./demo.txt", "./test/demo.txt");
    if (iRet == 0)
    {
        printf("link created");
    }
    else
    {
        printf("unable to create link");
    }
    return 0;
}