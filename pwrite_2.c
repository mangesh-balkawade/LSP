#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0, iRet = 0;
    off_t offset = 0;
    char Buffer[100] = "Pune";

    fd = open("./LSPX.txt",O_WRONLY);

    iRet = pwrite(fd,Buffer,4,10);

    offset = lseek(fd,0,SEEK_CUR);
    printf("Current offset is : %lld\n",offset);    // 15

    return 0;
}