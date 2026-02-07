#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    char Path[100];
    int iRet = 0;

    memset(Path,'\0',sizeof(Path));

    iRet = readlink("./Test/LSPl.txt",Path,sizeof(Path));

    if(iRet == -1)
    {
        printf("%s\n",strerror(errno));
        return -1;
    }

    Path[iRet] = '\0';
    
    printf("Data from readlink is : %s\n",Path);

    return 0;
}