#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{

    FILE *fp = NULL;
    char buffer[256];
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("------------------------Mervellous Memory Scanner-----------\n");

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fp);

    return 0;
}