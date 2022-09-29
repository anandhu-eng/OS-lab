#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid == -1)
    {
        printf("Process creation unsuccessfull!\n");
    }
    if(pid == 0)
    {
        printf("Child process\n");
    }
    if(pid != 0)
    {
        printf("Parent process\n");
    }
    printf("%d\n", pid);
}