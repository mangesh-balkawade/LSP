#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void showProcessInfo(int pid)
{
    FILE *fp = NULL;
    char line[80];

    char fileName[100];

    sprintf(fileName, "/proc/%d/status", pid);

    printf("Accessing the file %s\n", fileName);

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Unable to access system file\n");
        return;
    }

    printf("--------------- Process Info ------------\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (
            strncmp(line, "Name:", 5) == 0 ||
            strncmp(line, "State:", 6) == 0 ||
            strncmp(line, "Threads:", 8) == 0 ||
            strncmp(line, "Pid:", 4) == 0)
        {
            printf("%s", line);
        }
    }
}

int main()
{
    int pid = 0;
    printf("-----------------Marvellous Process Inspector---------\n");
    printf("Enter the pid of the process that you want to inspect\n");
    scanf("%d", &pid);

    if (pid <= 0)
    {
        printf("Invalid pid\n");
        return -1;
    }

    showProcessInfo(pid);

    return 0;
}