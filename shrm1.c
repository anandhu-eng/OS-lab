#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
    key_t key = ftok("shmfile", 65);
    printf("%d", key);
}