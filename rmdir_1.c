#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>

int main()
{
    int iRet = 0;

    iRet = rmdir("./Data");

    if(iRet == 0)
    {
        printf("Directory gets deleted\n");
    }
    else
    {
        printf("%s\n",strerror(errno));
    }
    
    return 0;
}