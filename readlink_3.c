#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    char Path[100];
    int iRet = 0;
    int fd = 0;
    char Arr[20];

    memset(Path,'\0',sizeof(Path));

    iRet = readlink("./Test/LSPl.txt",Path,sizeof(Path));

    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    Path[iRet] = '\0';
    
    printf("Data from readlink is : %s\n",Path);

    fd = open(Path,O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    iRet = read(fd,Arr,10);

    Arr[iRet] = '\0';

    printf("Data from original file : %s\n",Arr);

    close(fd);

    return 0;
}