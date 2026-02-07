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
    struct dirent *ptr = NULL;

    dp = opendir("./Data");

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    while(ptr = readdir(dp))
    {
        // fd = open(ptr->d_name,O_RDONLY);
        // iRet = read(fd, Arr, sizeof(Arr));
    }

    closedir(dp);
    
    return 0;
}