#include <stdio.h>
#include <unistd.h>
int main()
{
    int iPid = getppid();
    printf("PID of parent process is %d\n", iPid);
    return 0;
}