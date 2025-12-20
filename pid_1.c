#include <stdio.h>
#include <unistd.h>
int main()
{
    int iPid = getpid();
    printf("PID ofcurrent process is %d\n", iPid);
    return 0;
}