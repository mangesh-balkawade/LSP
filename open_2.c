#include <stdio.h>
#include <fcntl.h>

int main()
{

    int fd = open("second.c", O_RDWR);
    if (fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File open successfuly with fd \n %d\n", fd);
    }

    return 0;
}