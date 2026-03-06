#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#define DEVICE_PATH "/dev/marvellous_driver"
#define BUFFER_SIZE 1024

int main()
{
    int fd = 0;
    char read_buffer[BUFFER_SIZE] = {'\0'};
    char write_buffer[BUFFER_SIZE] = {'\0'};
    int iRet = 0;

    printf("Opening the marvellous device\n");

    // cat /dev/marvellous_driver
    fd = open(DEVICE_PATH, O_RDWR);

    if (fd == -1)
    {
        printf("Error: Unable to open Marvellois device\n");
        return -1;
    }

    printf("Marvellous device opened succesfuuly\n");

    printf("Enter the data for marvelllus driver\n");
    fgets(write_buffer, BUFFER_SIZE, stdin);

    write_buffer[strcspn(write_buffer, "\n")] = 0;

    printf("Writing to the marvellous device\n");

    // echo "Jay Ganesh..." > /dev/marvellous_driver
    iRet = write(fd, write_buffer, strlen(write_buffer));

    if (iRet < 0)
    {
        printf("Error:Unable to write into the marvellous driver");
        close(fd);
        return -1;
    }

    printf("Marvellous :Data sucessfuuly written tomarvellous driver\n");

    printf("Reading data \n");

    // cat /dev/marvellous_driver
    iRet = read(fd, read_buffer, BUFFER_SIZE);
    if (iRet < 0)
    {
        printf("Error:Unable to read the data from driver\n");
        close(fd);
        return -1;
    }

    read_buffer[iRet] = '\0';

    printf("Marvelllous : Data rerecived from marvellous driver as %s \n", read_buffer);
    close(fd);
    return 0;
}