#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("output.txt", O_RDWR);
    int iRet = unlink("output.txt");
    if (iRet == 0)
    {
        printf("deleted");
    }
    else
    {
        printf("unable to delete");
    }
    return 0;
}