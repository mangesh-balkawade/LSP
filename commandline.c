#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("inside command line process \n");

    printf("Command line arg are\n");
    for (int i = 0; i < argc; i++)
    {
        printf("arg name: %s\n", argv[i]);
    }
    return 0;
}