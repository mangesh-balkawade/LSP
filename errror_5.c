#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    int fd = 0;
    fd = open("lsp.txt", O_RDONLY);
    printf("Value of fd %d\n", fd);

    if (errno != 0)
    {
        switch (errno)
        {
        case ENOENT:
            printf("There is no such file ");
            break;
        case EACCES:
            printf("Unable to access due to permission");
            break;
        default:
            printf(strerror(errno));
            break;
        }
    }
    return 0;
}