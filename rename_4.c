#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int fd = open("./process.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("unable to open file \n");
    }

    int iRet = rename("./process.txt", "./test/hello.txt");

    if (iRet == 0)
    {
        printf("file renamed");
    }
    else
    {
        printf("error in file %s", strerror(errno));
        return -1;
    }

    char arr[100];
    iRet = read(fd, arr, 100);

    if (iRet != 0)
    {
        printf("Data Received %s", arr);
    }

    close(fd);

    return 0;
}