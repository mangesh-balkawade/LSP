#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0, iRet = 0;
    off_t offset = 0;
    char Buffer[100];

    fd = open("./LSP.txt",O_RDONLY);

    //offset = lseek(fd,10,SEEK_SET);
    //printf("Current offset is : %lld\n",offset);    // 10

    iRet = pread(fd,Buffer,5,10);

    printf("\n");

    write(1,Buffer,iRet);

    printf("\n");

    offset = lseek(fd,0,SEEK_CUR);
    printf("Current offset is : %lld\n",offset);    // 15

    return 0;
}