// Server Code
#include <stdio.h>      // print f scan f
#include <sys/socket.h> //socket bind listen connect accept
#include <string.h>     // meset memcmp
#include <stdlib.h>     // malloc
#include <unistd.h>     // close read write
#include <fcntl.h>      // create unlink etc
#include <netinet/in.h> // sockataddr_in
#include <arpa/inet.h>

int main()
{
    int serverSocketFd = 0;
    int iRet = 0;
    struct sockaddr_in serverAddr;
    int port = 11000;
    char buffer[1024] = {'\0'};

    // create tcp socket
    serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);

    // step 1
    if (serverSocketFd < 0)
    {
        printf("Unable to create socket \n");
        return -1;
    }

    printf("socket gets cretaed successfully with fd %d \n", serverSocketFd);

    // step 2 : connect with server

    memset(&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    iRet = connect(serverSocketFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    if (iRet == -1)
    {
        printf("unable to connect with server \n");
        return -1;
    }

    printf("client successfully connected withs server \n");

    // step 3 :read data from server
    iRet = read(serverSocketFd, buffer, sizeof(buffer) - 1);

    if (iRet <= 0)
    {
        printf("unable to read  data from server");
        return -1;
    }

    printf("data from server is %s \n", buffer);

    // step 4 : close all resources
    close(serverSocketFd);

    printf("terminating the client app");

    return 0;
}