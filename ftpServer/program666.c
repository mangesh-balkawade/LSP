#include <stdio.h>
#include <sys/socket.h>
int main()
{
    int serverSocket = 0;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        printf("Issue in server socket");
        return -1;
    }

    printf("socket gets created fd :%d \n", serverSocket);
    

    return 0;
}