//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing Inter Process Communication using shared memory

#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
    //generate unique key
    key_t key = ftok("shrm1.c", 65);
    //get unique id for the memory block after creating
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    //attach to the memory block just created
    char* str = (char*)shmat(shmid, (void*)0, 0);   
    printf("Data in the shared memory is:%s\n", str);
    //detaching the shared memory
    shmdt(str);
    //destroy the shared memory
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}