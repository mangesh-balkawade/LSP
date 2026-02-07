#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    // return two values
    int pipefd[2] = {0,0};
    int iRet = 0;

    iRet = pipe(pipefd);

    if(iRet == 0)
    {
        printf("Unnamed pipe gets created\n");
    }

    return 0;
}