#include<stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    printf("Inside Command Line Process\n");

    printf("Command Line arguments are : \n");
    
    for(i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }

    return 0;
}