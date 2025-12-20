#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    char fileName[] = "lsp.txt";
    int fd = 0;
    fd = open(fileName, O_RDONLY);

    int iRet = ftruncate(fd, 5);
    if (iRet == 0)
    {
        printf("Trncate Done");
    }
    else
    {
        printf("Unable to truncate");
    }
    return 0;
}