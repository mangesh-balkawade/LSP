#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
    printf("Demonnstration of errno\n");
    printf("%d\n", errno);
    return 0;
}