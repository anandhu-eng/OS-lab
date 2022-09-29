#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

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
        exit(1);
    }
    if(pid != 0)
    {
        wait(NULL);
        currentpid = getpid();
        printf("Parent process pid:%d\n", currentpid);
        exit(1);
    }
    //printf("%d\n", pid);
}