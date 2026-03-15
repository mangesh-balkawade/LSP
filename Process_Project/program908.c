#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("%s\n", getenv("HOME"));
    printf("%s\n", getenv("SHELL"));
    return 0;
}