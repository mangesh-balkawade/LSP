// Server Code
#include <stdio.h>      // print f scan f
#include <sys/socket.h> //socket bind listen connect accept
#include <string.h>     // meset memcmp
#include <stdlib.h>     // malloc
#include <unistd.h>     // close read write
#include <fcntl.h>      // create unlink etc
#include <netinet/in.h> // sockataddr_in

int main()
{
    int serverSocketFd = 0;
    int iRet = 0;
    int port = 11000;
    int clientSocketFd = 0;
    char *message = "Jay Ganesh From Server \n";

    /**
     *
     * struct sockaddr {
               sa_family_t sa_family;
               char        sa_data[14];
           }
     *
     */

    struct sockaddr_in sktAddr;

    // step 1 : create tcp socket
    serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocketFd < 0)
    {
        printf("Issue in server socket");
        return -1;
    }

    printf("socket gets created fd :%d \n", serverSocketFd);

    //  clean
    memset(&sktAddr, 0, sizeof(sktAddr));
    sktAddr.sin_addr.s_addr = INADDR_ANY;
    sktAddr.sin_family = AF_INET;
    sktAddr.sin_port = htons(port);

    // step2 : attach the socket to ip address
    iRet = bind(serverSocketFd, (struct sockaddr *)&sktAddr, sizeof(sktAddr));

    if (iRet == -1)
    {
        printf("issue in bind");
        close(serverSocketFd);
        return -1;
    }

    printf("bind opertion with socket is successfull \n");

    // listen     // fd       max no of client connection
    iRet = listen(serverSocketFd, 20);
    if (iRet == -1)
    {
        printf("listen unsuccessfull\n");
        close(serverSocketFd);
        return -1;
    }

    printf("Server is running on post no %d \n", port);

    // accept new socket request
    clientSocketFd = accept(serverSocketFd, NULL, NULL);

    if (clientSocketFd == -1)
    {
        printf("unable to accept request from client \n");
        close(serverSocketFd);
        return -1;
    }

    printf("request is accepted by server \n");

    // step 5 : send message to client
    write(clientSocketFd, message, strlen(message));

    // setp 6 : close all resources
    close(serverSocketFd);
    close(clientSocketFd);

    printf("terminating the server app");

    return 0;
}