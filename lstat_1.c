#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>

int main()
{
    struct stat sobj;
    int iRet = 0;

    iRet = lstat("./LSPL.txt",&sobj);

    printf("Inode number : %ld\n",sobj.st_ino);
    printf("Hardlink count : %ld\n",sobj.st_nlink);
    printf("Total size : %ld\n",sobj.st_size);
    printf("Block size : %ld\n",sobj.st_blksize);

    printf("File type is : %d\n",sobj.st_mode);

    return 0;
}