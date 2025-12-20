#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define SIZE_BUFFER 100

int main()
{
    int fd = open("Hole.txt", O_WRONLY | O_CREAT);

    char buffer[SIZE_BUFFER];

    // similar like array.fills
    memset(buffer, '\0', SIZE_BUFFER); // filewith '\0'

    if (fd < 0)
    {
        printf("unable to open the file\n");
        printf("Reson for failure %s\n", strerror(errno));
    }

    printf("file open successfully fd %d \n", fd);

    int iRet = lseek(fd, 4100, SEEK_SET);
    printf("current offset is %d \n", iRet);
    iRet = write(fd, "end", 3);
    printf("byte returns successfully %d \n", iRet);

    close(fd);
    return 0;
}