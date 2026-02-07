#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *Demo(void *p)
{
    int iSum = 0;
    int *ptr = NULL;

    ptr = (int *)malloc(sizeof(int));

    printf("Inside thread with value \n");

    iSum = (*((int *)p + 0)) + (*((int *)p + 1)) + (*((int *)p + 2)) + (*((int *)p + 3));

    *ptr = iSum;

    pthread_exit(ptr);
}

int main()
{
    pthread_t TID;
    int iRet = 0;
    int *Value = NULL;
    int Arr[] = {11, 21, 51, 101};

    printf("Main thread started\n");

    iRet = pthread_create(
        &TID,      // Thread ID
        NULL,      // Thread attributes
        Demo,      // Thread callback function
        (int *)Arr // Parameters for the callback function
    );

    if (iRet == 0)
    {
        printf("Thread gets created succesfully with TID : %lu\n", (unsigned long)TID);
    }

    pthread_join(TID, &Value);

    printf("Summation is : %d\n", *Value);

    printf("End of main thread\n");

    return 0;
}