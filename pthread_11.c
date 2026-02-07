#include <stdio.h>
#include <pthread.h>

void *Demo(void *p)
{
    printf("Inside Demo thread\n");
    return NULL;
}

void *Hello(void *p)
{
    printf("Inside Hello thread\n");
    return NULL;
}

int main()
{
    pthread_t TID1, TID2;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
        &TID1, // Thread ID
        NULL,  // Thread attributes
        Demo,  // Thread callback function
        NULL   // PArameters for the callback function
    );

    if (iRet == 0)
    {
        printf("Thread gets created succesfully with TID : %lu\n", (unsigned long)TID1);
    }

    iRet = pthread_create(
        &TID2, // Thread ID
        NULL,  // Thread attributes
        Hello, // Thread callback function
        NULL   // PArameters for the callback function
    );

    if (iRet == 0)
    {
        printf("Thread gets created succesfully with TID : %lu\n", (unsigned long)TID2);
    }

    // wait
    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);

    printf("End of main thread\n");

    return 0;
}