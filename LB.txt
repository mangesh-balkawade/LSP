#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>

void * Demo(void *p)
{
    int fd = 0;
    int iRet = 0, iCount = 0, i = 0;
    
    char Buffer[1024] = {'\0'};

    fd = open("PPA.txt",O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCount++;
            }
        }
    }

    close(fd);

    printf("Number of capital characters : %d\n",iCount);

    return NULL;
}

void * Hello(void *p)
{
    int fd = 0;
    int iRet = 0, iCount = 0, i = 0;
    
    char Buffer[1024] = {'\0'};

    fd = open("LB.txt",O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
    {
        for(i = 0; i < iRet; i++)
        {
            if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
            {
                iCount++;
            }
        }
    }

    close(fd);

    printf("Number of small characters : %d\n",iCount);

    return NULL;
}

int main()
{
    pthread_t TID1, TID2;
    int iRet = 0;

    printf("Main thread started\n");

    iRet = pthread_create(
                            &TID1,   // Thread ID
                            NULL,   // Thread attributes
                            Demo,   // Thread callback function
                            NULL    // PArameters for the callback function
                        );


    if(iRet == 0)
    {
        printf("Thread gets created succesfully with TID : %lu\n",(unsigned long)TID1);
    }

    iRet = pthread_create(
                            &TID2,   // Thread ID
                            NULL,   // Thread attributes
                            Hello,   // Thread callback function
                            NULL    // PArameters for the callback function
                        );


    if(iRet == 0)
    {
        printf("Thread gets created succesfully with TID : %lu\n",(unsigned long)TID2);
    }

    // wait
    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    
    printf("End of main thread\n");

    return 0;
}