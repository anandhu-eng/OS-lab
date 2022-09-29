#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>

void producer(int* mutex, int* buffer)
{
    printf("Waiting to get a lock!\n");
    while(*mutex == 0)
    {
        
    }
    printf("Got a lock!\n");
    *mutex = 0;
    sleep(5);
    *buffer = *buffer + 1;
    *mutex = 1;
}

void consumer(int* mutex, int* buffer)
{
    printf("Waiting to get a lock!\n");
    while(*mutex==0)
    {

    }
    printf("Got a lock!\n");
    *mutex = 0;
    sleep(5);
    *buffer = *buffer - 1;
    *mutex = 1;
}

int main()
{
    int choice, max_buffer = 5;
    //declaring shared memory for mutex
    key_t key_mutex = ftok("prod.c", 65);
    int shmid = shmget(key_mutex, 1024, 0666|IPC_CREAT);
    int* mutex = shmat(shmid, (void*)0, 0);
    *(mutex) = 1;
    //declaring shared memory for buffer
    key_t key_buffer = ftok("prod1.c", 65);
    int shmid_buffer = shmget(key_buffer, 1024, 0666|IPC_CREAT);
    int* buffer = shmat(shmid_buffer, (void*)0, 0);
    *(buffer) = 0;
    printf("%d %d", *(mutex), *buffer);
    //main code
    while(1)
    {
        printf("Enter the option\n1.Producer\n2.Consumer\n3.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            //producer
            if(((*buffer) < max_buffer))
            {
                printf("Entered producer\n");
                producer(mutex, buffer);
            }
            else
            {
                printf("Error! buffer size exceeded!\n");
            }
            break;
        
        case 2:
            //consumer
            if(*(buffer) > 0)
            {
                printf("Entered consumer");
                consumer(mutex, buffer);
            }
            else
            {
                printf("Error! buffer size is in lower bound!\n");
            }
            break;
        
        case 3:
            return 1;

        default:
            printf("Invalid choice!");
            break;
        }
    }
    shmctl(shmid, IPC_RMID, NULL);
    shmctl(shmid_buffer, IPC_RMID, NULL);
}