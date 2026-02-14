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

void sendFileToClient(int clientSocket, char *fileName)
{

    int fd = 0;
    struct stat sobj;
    char buffer[1024];
    int bytesRead = 0;
    char header[64] = {'\0'};

    //
    printf("file name is %s \n", fileName);
    fd = open(fileName, O_RDONLY);
    // remove new line
    //  fileName[strcspn]

    if (fd < 0)
    {                                    // unable to open file
        write(clientSocket, "ERR\n", 4); // send err message to client
        return;
    }

    stat(fileName, &sobj);

    //              size
    // header : "OK 1700"

    snprintf(header, sizeof(header), "OK %ld\n", (long)sobj.st_size);

    // write header to client
    write(clientSocket, header, strlen(header));

    // send data to client
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0)
    {
        write(clientSocket, buffer, bytesRead);
    }
}

/**
 * Command Line Arguments Application
 * 1st arg: Port No (direct first exe name excluded )
 * ./server 3000
 * argv[0] - server
 * argc[1] - 3000
 */
int main(int argc, char *argv[])
{

    int port = 0;
    int serverSocket = 0;
    int clientSocket = 0;
    int iRet = 0;

    pid_t pid = 0;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    char fileName[50] = {'\0'};

    socklen_t addrLen = sizeof(clientSocket);

    if (argc < 2 || argc > 2)
    {
        printf("Please Provide Required Arguments \n");
        printf("Please Provide Executed Name \n Port No \n");
        return -1;
    }

    // port no of server
    port = atoi(argv[1]);

    /**
     * Step 1 : Create TCP Socket
     */

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        printf("Unable to crete socket server \n");
        return -1;
    }

    /**
     * Step 2 : Bind Socket To IP & Port
     */

    memset(&serverAddr, 0, sizeof(serverAddr));

    // initialize the structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY; // all network

    iRet = bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (iRet == -1)
    {
        printf("Unable to bind \n");
        close(serverSocket);
        return -1;
    }

    /**
     * Step 3 : Listen for client connection
     */

    iRet = listen(serverSocket, 20);

    if (iRet == -1)
    {
        printf("Server unable to listen request \n");
        close(serverSocket);
        return -1;
    }

    printf("Server is running on post %d\n", port);

    /**
     * Loop to accept multiple client request
     */

    while (1)
    {
        /**
         * Step 4 : Accept the client request
         */

        memset(&clientAddr, 0, sizeof(clientAddr));

        printf("Server is waiting for client request \n");

        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen);
        if (clientSocket < 0)
        {
            printf("Unable to accept client request \n");
            continue; // for while
        }

        printf("Client gets connected : %s \n", inet_ntoa(clientAddr.sin_addr));

        /**
         * Step 5 : Create new process to handle client request
         */

        pid = fork();

        if (pid < 0)
        {
            printf("Unable to create new process for client request \n");
            close(clientSocket);
            continue;
        }

        // new process gets created for client
        if (pid == 0)
        {
            printf("new process is created for client request");
            close(serverSocket);

            iRet = read(clientSocket, fileName, sizeof(fileName));

            printf("Requested file by client %s \n", fileName);

            sendFileToClient(clientSocket, fileName);

            close(clientSocket);

            printf("File transfer done & client disconnected \n");

            exit(0);
        } // end of if
        else // parent process
        {
            close(clientSocket);
        }

    } // end of while

    close(serverSocket);

    return 0;
    // End of main
}