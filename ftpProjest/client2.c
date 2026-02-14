#include <stdio.h>      // print f scan f
#include <sys/socket.h> //socket bind listen connect accept
#include <string.h>     // meset memcmp
#include <stdlib.h>     // malloc
#include <unistd.h>     // close read write
#include <fcntl.h>      // create unlink etc
#include <netinet/in.h> // sockataddr_in
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdbool.h>

int readLine(int sock, char *line, int max)
{
    int i = 0;
    char ch = '\0';
    int n = 0;
    while (i < max - 1)
    {
        n = read(sock, &ch, 1);

        if (n <= 0)
        {
            break;
        }

        line[i++] = ch;

        if (ch == '\n')
        {
            break;
        }
    } // end of while

    line[1] = '\0';
    return i;
} // end of readline

/**
 * Command Line Arguments Application
 * 1st arg: IP Address
 * 2nd arg : Port No
 * 3rd arg : Target file name
 * 4th arg : New file name
 *
 * /client  127.0.0.1 3000      Demo.txt  a.txt
 *  argv[0] argv[1]   argv[2]   argv[3]   argv[4]
 *
 */
int main(int argc, char *argv[])
{

    int sock = 0;
    struct sockaddr_in serverAddr;
    char *ip = NULL;          // argv[1]
    int port = 0;             // argv[2]
    char *fileName = NULL;    // argv[3]
    char *outFileName = NULL; // argv[4]
    char header[64] = {'\0'};

    int iRet = 0;

    if (argc != 5)
    {
        printf("Please Provide Required Arguments \n");
        printf("Please Provide Below Args \n");
        printf("1st arg: IP Address \n 2nd arg : Port No \n3rd arg : Target file name \n4th arg : New file name \n");
        return -1;
    }

    // store cmd  line args in veriables
    ip = argv[1];
    port = atoi(argv[2]);
    fileName = argv[3];
    outFileName = argv[4];

    /**
     * Step 1 : Create TCP Socket
     */

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        printf("Unable to create socket for client \n");
        return -1;
    }

    printf("Client Socket Connected \n");

    /**
     * Step 2 : Connect with Server
     */

    memset(&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    // convert ip address to binary format
    inet_pton(AF_INET, ip, &serverAddr.sin_addr.s_addr);

    iRet = connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    if (iRet == -1)
    {
        printf("Unable to connect to server\n");
        close(sock);
        return -1;
    }

    /**
     * Step 3 :  Sending file name to server
     */
    write(sock, fileName, strlen(fileName));
    write(sock, "\n", 1);

    /**
     * Step 4 : Read The Header
     */

    iRet = readLine(sock, header, sizeof(header));

    if (iRet <= 0)
    {
        printf("Did not recived the header \n");
        close(sock);
        return -1;
    }

    long fileSize = 0;
    sscanf(header, "OK %ld", &fileSize);
    printf("file size is : %ld \n", fileSize);

    /**
     * Step 5 : Create new file
     */

    int outFd = 0;
    outFd = open(outFileName, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (outFd < 0)
    {
        printf("Unable to created  downloaded file \n");
    }

    char buffer[1024] = {'\0'};
    long received = 0;
    long remaining = 0;
    int n = 0;
    int toRead = 0;

    while (received < fileSize)
    {
        remaining = fileSize - received;
        if (remaining > 1024)
        {
            toRead = 1024;
        }
        else
        {
            toRead = remaining;
        }

        n = read(sock, buffer, toRead);

        write(outFd, buffer, n);
        received += n;
    } // end of while

    close(outFd);
    close(sock);

    if (received == fileSize)
    {
        printf("download complete ...\n");
        return 0;
    }
    else
    {
        printf("Unable to completed download..\n");
        return -1;
    }

    return 0;
    // End of main
}