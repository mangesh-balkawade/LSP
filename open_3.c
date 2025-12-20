#include <stdio.h>
#include <fcntl.h>

int main()
{

    int fd = open("second.c", O_CREAT, 0777);
    if (fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File successfuly created with fd \n %d\n", fd);
    }

    return 0;
}