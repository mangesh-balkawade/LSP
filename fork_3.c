#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid = 0;
    pid = fork();
    if (pid == 0)
    {
        printf("Child Says : PID of current process %d, PID of current process %d , return value of fork %d \n",
               getpid(), getppid(), pid);
    }
    else
    {
        printf("Parent Says: PID of current process %d, PID of current process %d , return value of fork %d \n",
               getpid(), getppid(), pid);
    }

    return 0;
}