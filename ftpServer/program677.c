#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("no of arguments %d \n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argument no %d is %s \n", i + 1, argv[i]);
    }
    return 0;
}