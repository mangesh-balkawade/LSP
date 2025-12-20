#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{

    int fd = creat("lsp.txt", 0777);
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