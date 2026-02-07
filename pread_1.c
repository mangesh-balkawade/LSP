#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int fd = 0;
    off_t offset = 0;
    char Buffer[100];

    fd = open("./LSP.txt",O_RDONLY);

    offset = lseek(fd,0,SEEK_SET);

    printf("Current offset is : %lld\n",offset);    // 0

    read(fd,Buffer,10);

    offset = lseek(fd,0,SEEK_CUR);

    printf("Current offset is : %lld\n",offset);    // 10

    return 0;
}