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
    // create tcp socket
    serverSocketFd = socket(AF_INET, SOCK_STREAM, 0);

    // step 1
    if (serverSocketFd < 0)
    {
        printf("Unable to create socket \n");
        return -1;
    }

    printf("socket gets cretaed successfully with fd %d \n", serverSocketFd);

    return 0;
}