#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    if (pid < 0)
    {
        printf("Unable to create child process \n");
        return -1;
    }

    if (pid == 0)
    {
        printf("Child process gets created successfully \n");
    }
    return 0;
}