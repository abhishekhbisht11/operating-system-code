//orphan process
#include <stdio.h> 
#include<unistd.h>
 int main()
{
    int pid = fork();
    if (pid > 0)
    printf("Parent Process.\n");
    else if (pid == 0)
    {
        sleep(10);
        printf("Child Process.\n");
    }
    return 0;
}
