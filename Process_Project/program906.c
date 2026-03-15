#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int ans = 0;
    if (argc != 3)
    {
        printf("Please provided required args:\n");
        return -1;
    }

    ans = atoi(argv[1]) + atoi(argv[2]);

    printf("Sum is %d\n", ans);

    return 0;
}