#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

int main()
{
    printf("Current Directory Name : %s\n",getcwd());   // Error
  
    return 0;
}