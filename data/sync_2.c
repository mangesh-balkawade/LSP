#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    int fd = open("demo.txt", O_CREAT | O_WRONLY | O_APPEND, 0777);
    char buffer[] = "Indiaismycountry";
    if (fd < 0)
    {
        printf("unable to open the file\n");
        printf("Reson for failure %s\n", strerror(errno));
    }
    printf("file open successfully fd %d \n", fd);

    int iRet = 0;
    iRet = write(fd, buffer, 16); // override the context

    printf("%d bytes get successfully return ", iRet);
    close(fd);

    sync();

    return 0;
}