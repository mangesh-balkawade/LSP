#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{

    int fd = creat(argv[1], 0777);
    if (fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File successfuly created with fd \n %d\n", fd);
    }

    close(fd);
    return 0;
}