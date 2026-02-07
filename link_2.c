#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>

int main()
{
    int iRet = 0;

    iRet = link("./Demo.txt", "./Test/Demo.txt");

    if(iRet == 0)
    {
        printf("link is succesful\n");
    }


    return 0;
}