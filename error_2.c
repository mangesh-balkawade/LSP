#include<stdio.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    
    fd = open("Marvellous.txt",O_RDONLY);
    
    printf("Value of fd is : %d\n",fd);
    printf("Value of errno is : %d\n",errno);

    return 0;
}