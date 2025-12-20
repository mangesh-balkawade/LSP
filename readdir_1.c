#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

int main()
{
    DIR *dp = NULL;
    dp = opendir("./data");
    if (dp == NULL)
    {
        printf("unable to open dir %s", strerror(errno));
        return -1;
    }

    struct dirent *ptr = NULL;

    ptr = readdir(dp);
    printf("INode no %lu: \n", ptr->d_ino);
    printf("file  name : %s \n", ptr->d_name);

    return 0;
}