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
    char arr[50];
    memset(arr, '\0', sizeof(arr));
    getcwd(arr, sizeof(arr));
    printf("current working directory %s \n", arr);

    chdir("data");

    memset(arr, '\0', sizeof(arr));
    getcwd(arr, sizeof(arr));
    printf("current working directory %s \n", arr);

    return 0;
}