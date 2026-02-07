#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>

int main()
{
    struct stat sobj;
    int iRet = 0;

    iRet = stat("Demo.txt",&sobj);

    printf("Inode number : %ld\n",sobj.st_ino);
    printf("Hardlink count : %ld\n",sobj.st_nlink);
    printf("Total size : %ld\n",sobj.st_size);
    printf("Block size : %ld\n",sobj.st_blksize);

    return 0;
}