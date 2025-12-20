#include <stdio.h>
#include <fcntl.h>

int main()
{

    int fd = open("first.c", O_RDWR);
    if (fd == -1)
    {
        printf("Unable to open file\n");
    }

    printf("File open successfuly with fd \n %d\n", fd);

    return 0;
}