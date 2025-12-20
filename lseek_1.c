#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define SIZE_BUFFER 100

int main()
{
    int fd = open("lsp.txt", O_RDONLY);
    char buffer[SIZE_BUFFER];

    // similar like array.fills
    memset(buffer, '\0', SIZE_BUFFER); // filewith '\0'

    if (fd < 0)
    {
        printf("unable to open the file\n");
        printf("Reson for failure %s\n", strerror(errno));
    }

    printf("file open successfully fd %d \n", fd);
    int iRet = 0;
    iRet = lseek(fd, 10, SEEK_CUR);

    printf("updated file offset is %d\n", iRet);

    close(fd);
    return 0;
}