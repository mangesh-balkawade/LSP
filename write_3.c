#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    int fd = open("lsp.txt", O_WRONLY | O_APPEND);
    char buffer[] = "Indiaismycountry";
    if (fd < 0)
    {
        printf("unable to open the file\n");
        printf("Reson for failure %s\n", strerror(errno));
    }
    printf("file open successfully fd %d \n", fd);

    int iRet = 0;
    iRet = write(fd, buffer, 16); // overidie the context

    printf("%d bytes get successfully return ", iRet);
    close(fd);

    return 0;
}