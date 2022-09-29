#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int pid = fork();
    if(pid==0)
    {
        printf("Child process!\n");
        char* arg[] = {"/bin/ls", "-1", 0};     //-1 is used to specify that the files should be printed one afer another
        execv("/bin/ls", arg);
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Parent process!\n");
        char* arg1[] = {"/bin/date", 0};        //0 is used to convey the exit status(if ok)
        execv("/bin/date", arg1);
    }
}