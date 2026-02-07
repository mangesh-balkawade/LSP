#include<stdio.h>

int main(int argc, char *argv[])
{
    int iCnt = 0;

    printf("Number of command line args are : %d\n",argc);
    
    for(iCnt = 0; iCnt < argc; iCnt++)
    {
        printf("%s\n",argv[iCnt]);
    }
    
    return 0;
}