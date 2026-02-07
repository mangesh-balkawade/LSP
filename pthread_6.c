#include <stdio.h>
#include <pthread.h>

void *Demo(void *p)
{
    printf("Inside thread with value : %d\n", (int)p);

    return NULL;
}

int main()
{
    pthread_t TID;
    int iRet = 0;
    int Value = 0;
    int no = 11;

    printf("Main thread started\n");

    iRet = pthread_create(
        &TID,     // Thread ID
        NULL,     // Thread attributes
        Demo,     // Thread callback function
        (int *)no // Parameters for the callback function
    );

    if (iRet == 0)
    {
        printf("Thread gets created succesfully with TID : %lu\n", (unsigned long)TID);
    }

    // wait
    pthread_join(TID, NULL);

    printf("End of main thread\n");

    return 0;
}