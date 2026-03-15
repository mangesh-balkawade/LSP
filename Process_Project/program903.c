#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Inside myexe process with pid : %d\n", getpid());
    return 0;
}