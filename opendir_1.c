#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>

int main()
{
    DIR *dp = NULL;

    dp = opendir("./Data");

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }
    else
    {
        printf("Directory gets succesfully opened\n");
    }

    return 0;
}