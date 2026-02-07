#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    int fd = 0;
    char Buffer[100] = {'\0'};
    int iRet = 0;

    fd = open("Demo.txt",O_RDONLY);
    
    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reson : %s\n",strerror(errno));
        return -1;
    }

    printf("File succesfully opened with fd : %d\n",fd);

    iRet = read(fd, Buffer, 10);       

    printf("%d bytes gets succesfully read\n",iRet);

    printf("Data from file  : %s\n",Buffer);

    close(fd);
    
    return 0;
}