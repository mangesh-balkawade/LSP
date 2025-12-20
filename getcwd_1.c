#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    printf("current directory name \n %s \n ", getcwd()); // errror
    return 0;
}