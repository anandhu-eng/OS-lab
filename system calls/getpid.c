#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid = fork();
    int currentpid;
    if(pid == -1)
    {
        printf("Process creation unsuccessfull!\n");
    }
    if(pid == 0)
    {
        currentpid = getpid();
        printf("Child process pid:%d\n", currentpid);
    }
    if(pid != 0)
    {
        currentpid = getpid();
        printf("Parent process pid:%d\n", currentpid);
    }
    printf("%d\n", pid);
}