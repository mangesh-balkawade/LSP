#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void getSectionType(char *details, char *permission, char *section)
{
    if (strcmp(details, "[heap]") == 0)
    {
        strcpy(section, "HEAP");
    }
    else if (strcmp(details, "[stack]") == 0)
    {
        strcpy(section, "STACK");
    }
    else if (strcmp(details, "[vvar]") == 0)
    {
        strcpy(section, "VVAR");
    }
    else if (strcmp(details, "[vdso]") == 0)
    {
        strcpy(section, "VDSO");
    }
    // else if (permission[2] == "x")
    // {
    //     strcpy(section, "TEXT");
    // }
    // else if (permission[1] == "w")
    // {
    //     strcpy(section, "DATA");
    // }
    else
    {
        strcpy(section, "OTHER");
    }
}

void showMemLayout(int pid)
{
    FILE *fp = NULL;
    char line[80];

    char fileName[100];

    sprintf(fileName, "/proc/%d/maps", pid);

    printf("Accessing the file %s\n", fileName);

    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        printf("Unable to access system file\n");
        return;
    }

    printf("--------------- Memory Layout ------------\n");

    printf("------Header----------");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char address[100], permission[10], offset[20], dev[20], details[300] = "";
        unsigned long inode;
        unsigned long start, end;
        unsigned long sizekb;
        char section[50];

        int ret = 0;
        ret = sscanf(line, "%s %s %s %s %lu %[^\n]", address, permission, offset, dev, &inode, details);

        if (ret >= 5)
        {
            sscanf(address, "%lx-%lx", &start, &end);
            sizekb = (end - start) / 1024;

            getSectionType(details, permission, section);

            if (strlen(details) == 0)
            {
                strcpy(details, "Anonymous");
            }

            printf("%lx %lx %lu %s %s %s\n", start, end, sizekb, permission, section, details);
        }
    }

    printf("------------------------");

    fclose(fp);
}

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
    showMemLayout(pid);

    return 0;
}

/**
 *
 *
 * TEXT / Code Binary Instructions
 *
 * VDSO Virtual Dynamic Shred Object
 * VVAR Virtual Variables
 * VSYSCALL Virtaul System Call Page
 * Other Other memory regions
 *
 */