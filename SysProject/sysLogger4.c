
//   0       1               2
// ./myexe
//./myexe /home/desktop/demo 5

/**
 * Header file inclusion
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/statvfs.h>

/**
 * Gobal veriable creation
 */

static volatile sig_atomic_t stop_flag = 0;

// ctrl + c handler
static void sigint_handler(int sig)
{
    // not used veriable
    (void)sig;

    printf("Marvellous System Logger Is Terminating\n");
    // Tell the threads to stop the execution
    stop_flag = 1;
}

typedef struct // structur which holds on system info
{
    double cpu;  // cpu usage %
    double mem;  // ram usage %
    double disk; // disk usage %
} Snapshot;

//  Global object which holds information
static Snapshot snap;

// mutext lock for critical section
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

// Default path for disk
static const char *disk_path = "/";

// Sleep timer for log
static int interval_sec = 2;

/**
 * Helper function definations
 */

/**
 * Thread proc for thread which collets system info
 */
static void *collector_thread(void *arg)
{
    (void)arg;
    printf("Inside collector thread\n");

    while (!stop_flag)
    {
    }
    return NULL;
}

/**
 * Thread proc for thread which writes system info
 */
static void *logger_thread(void *arg)
{
    (void)arg;
    printf("Inside logger thread\n");
    int fd = 0;
    fd = open("Marvellous_Log.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);
    char welcome[] = "Marvellous System Logger";
    write(fd, welcome, strlen(welcome));
    while (!stop_flag)
    {
        // write info of structure snap into the file
    }
    close(fd);
    return NULL;
}

/**
 * Entry point function of project
 */

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        disk_path = argv[1];
    }
    else if (argc == 3)
    {
        disk_path = argv[1];
        interval_sec = atoi(argv[2]);
    }

    printf("Marvellous System Logger\n");
    printf("Path is %s\n", disk_path);
    printf("Interval is %d\n", interval_sec);

    // structure for handling ctrl+c
    struct sigaction sa;

    memset(&sa, 0, sizeof(sa));

    sa.sa_handler = sigint_handler;

    sigaction(SIGINT, &sa, NULL);

    pthread_t t_collect; // collect info
    pthread_t t_log;     // log the info

    pthread_create(&t_collect, NULL, collector_thread, NULL);
    pthread_create(&t_log, NULL, logger_thread, NULL);

    // main thread waiting for child thread to terminate
    pthread_join(t_collect, NULL);
    pthread_join(t_log, NULL);

    printf("Terminating the marverlllous sytem loger\n");

    return 0;
}