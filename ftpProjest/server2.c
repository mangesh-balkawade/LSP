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

/**
 * Command Line Arguments Application
 * 1st arg: Port No (direct first exe name excluded )
 * ./server 9000
 * argv[0] - server
 * argc[1] - 9000
 */
int main(int argc, char *argv[])
{

    int port = 0;
    int serverSocket = 0;
    int clientSocket = 0;
    int iRet = 0;

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

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

    } // end of while

    return 0;
    // End of main
}