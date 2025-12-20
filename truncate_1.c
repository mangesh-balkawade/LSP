#include <stdio.h>
#include <unistd.h>
int main()
{
    char fileName[] = "lsp.txt";
    int iRet = truncate(fileName, 10);
    if (iRet == 0)
    {
        printf("Trncate Done");
    }
    else
    {
        printf("Unable to truncate");
    }
    return 0;
}