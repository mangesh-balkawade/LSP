
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
#include <sys/sysinfo.h>
#include <time.h>

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

static void set_log_filename(char *fileName, size_t size)
{
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Format: Log_YYYYMMDD_HHMMSS.txt
    // %Y: Year, %m: Month, %d: Day, %H: Hour, %M: Min, %S: Sec
    strftime(fileName, size, "MarvellosLogger_%Y%m%d_%H%M%S.txt", tm_info);
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
static char *disk_path = "/";

// Sleep timer for log
static int interval_sec = 2;

/**
 * Helper function definations
 */

/**
 * Function to collect cpu info
 */

static double cpu_percentage()
{
    long double a[4], b[4];
    char buffer[256];
    int fd;

    // --- First reading ---
    fd = open("/proc/stat", O_RDONLY);
    if (fd < 0)
        return -1.0;

    read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    sscanf(buffer, "cpu %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);

    usleep(100000);

    fd = open("/proc/stat", O_RDONLY);
    if (fd < 0)
        return -1.0;

    read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    sscanf(buffer, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);

    // Calculation Logic
    long double load_a = a[0] + a[1] + a[2];
    long double total_a = load_a + a[3];

    long double load_b = b[0] + b[1] + b[2];
    long double total_b = load_b + b[3];

    if (total_b - total_a == 0)
        return 0.0;

    return (double)((load_b - load_a) / (total_b - total_a)) * 100.0;
}

/**
 * Function to collect ram info
 */

static double ram_percentage()
{
    struct sysinfo info;
    if (sysinfo(&info) != 0)
    {
        return -1.0;
    }

    long total_ram = info.totalram * info.mem_unit;
    long free_ram = info.freeram * info.mem_unit;
    long used_ram = total_ram - free_ram;

    return ((double)used_ram / (double)total_ram) * 100.0;
}

/**
 * Function to collect disk info
 */

static double disk_percentage(char *path)
{
    struct statvfs stat;

    if (statvfs(path, &stat) != 0)
    {
        return -1.0;
    }

    // Total blocks * size of block
    double total = (double)stat.f_blocks * (double)stat.f_frsize;
    // Free blocks available
    double free = (double)stat.f_bavail * (double)stat.f_frsize;
    double used = total - free;

    return (used / total) * 100.0;
}

/**
 * Thread proc for thread which collets system info
 */
static void *collector_thread(void *arg)
{
    (void)arg;
    printf("Inside collector thread\n");

    double c = 0.0,
           m = 0.0,
           d = 0.0;

    // Enter if ctrl+c is not arrived
    while (!stop_flag)
    {
        // Calculate the current resource usage
        double c = cpu_percentage();
        double m = ram_percentage();
        double d = disk_percentage(disk_path);

        // start the critical section
        pthread_mutex_lock(&mtx);
        snap.cpu = c;
        snap.mem = m;
        snap.disk = d;
        pthread_mutex_unlock(&mtx);
        // end of critical section
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

    char fileName[100] = {'\0'};
    set_log_filename(fileName, sizeof(fileName));

    fd = open(fileName, O_CREAT | O_WRONLY | O_APPEND, 0666);

    char welcome[] = "Marvellous System Logger";
    write(fd, welcome, strlen(welcome));

    double c = 0.0,
           m = 0.0,
           d = 0.0;

    while (!stop_flag)
    {
        // write info of structure snap into the file
        pthread_mutex_lock(&mtx);

        double c = snap.cpu;
        double m = snap.mem;
        double d = snap.disk;

        // write to file
        // sprintf create string to write the info into log file
        char line[256];

        // Format: CPU: 12.50% RAM: 45.20% DISK: 30.10%
        int len = snprintf(line, sizeof(line),
                           "CPU: %.2f%%, RAM: %.2f%%, DISK: %.2f%%\n",
                           c, m, d);

        if (len > 0 && len < sizeof(line))
        {
            write(fd, line, len);
        }

        pthread_mutex_unlock(&mtx);

        // sleep for interval
        for (int i = 0; i < interval_sec && !stop_flag; i++)
        {
            sleep(1);
        }
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