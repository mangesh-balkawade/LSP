#include <stdio.h>      // print f scan f
#include <sys/socket.h> //socket bind listen connect accept
#include <string.h>     // meset memcmp
#include <stdlib.h>     // malloc
#include <unistd.h>     // close read write
#include <fcntl.h>      // create unlink etc
#include <netinet/in.h> // sockataddr_in

int main()
{
    int serverSocket = 0;
    int iRet = 0;
    int port = 11000;

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
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        printf("Issue in server socket");
        return -1;
    }

    printf("socket gets created fd :%d \n", serverSocket);

    //  clean
    memset(&sktAddr, 0, sizeof(sktAddr));
    sktAddr.sin_addr.s_addr = INADDR_ANY;
    sktAddr.sin_family = AF_INET;
    sktAddr.sin_port = htons(port);

    // step2 : attach the socket to ip address
    iRet = bind(serverSocket, (struct sockaddr *)&sktAddr, sizeof(sktAddr));

    if (iRet == -1)
    {
        printf("issue in bind");
        close(serverSocket);
        return -1;
    }

    printf("bind opertion with socket is successfull \n");

    return 0;
}