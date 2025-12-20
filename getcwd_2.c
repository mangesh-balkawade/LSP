#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    char arr[50];
    memset(arr, '\0', sizeof(arr));
    getcwd(arr, sizeof(arr));
    printf("current working directory %s", arr);
    return 0;
}