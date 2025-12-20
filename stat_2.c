#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    struct stat sobj;
    int iRet = stat("lsp.txt", &sobj);
    if (iRet == 0)
    {
        printf("inode no %lu \n", sobj.st_ino);
        printf("hardlink count %lu \n", sobj.st_nlink);
        printf("total size %lu \n", sobj.st_size);
        printf("block size %lu \n", sobj.st_blksize);
    }
    else
    {
        printf("stats not working");
        return -1;
    }
    return 0;
}