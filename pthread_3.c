#include <stdio.h>
#include <pthread.h>
// you can pass anything
void *Demo(void *p)
{
    printf("Inside thread\n");
    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
        &TID, // Thread ID
        NULL, // Thread attributes
        Demo, // Thread callback function
        NULL  // PArameters for the callback function
    );

    if (iRet == 0)
    {
        printf("Thread gets created succesfully\n");
    }

    // wait

    printf("End of main thread\n");

    return 0;
}