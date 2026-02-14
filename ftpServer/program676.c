#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("no of cmd argument are %d \n", argc);
    if (argc != 5)
    {
        printf("Unable to proceedas invalid no of arguments provide \n");
        printf("provide :\n");
        printf("IP Address\n Post No \n Targeted File \n New File Name \n");
        return -1;
    }

    printf("Executable name %s \n", argv[0]);
    printf("IP Address %s \n", argv[1]);
    printf("Port No %s \n", argv[2]);
    printf("Targeted file %s \n", argv[3]);
    printf("New File Name %s \n", argv[4]);
    return 0;
}