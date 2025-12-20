#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid = 0;
    pid = fork();
    printf("PID%d PPID %d returnf%d\n", getpid(), getppid(), pid);
    return 0;
}