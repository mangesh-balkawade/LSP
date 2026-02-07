#include<stdio.h>
#include<string.h>
#include<errno.h>

int main()
{
    int iRet = 0;

    iRet = rename("DemoX.txt","Demo.txt");

    if(iRet == 0)
    {
        printf("Rename succesful\n");
    }
    else
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    return 0;
}