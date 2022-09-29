//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing firstfit memory allocation

#include<stdio.h>

struct details
{
    int pos;
    int size;
};

int main()
{
    int nblk, nproc, i, j, flag = 0;
    printf("Enter the number of memory block:");
    scanf("%d", &nblk);
    printf("Enter the number of processes:");
    scanf("%d", &nproc);
    struct details mblcks[nblk];
    int proc[nproc];
    printf("Enter the size of the memory blocks:\n");
    for(i=0;i<nblk;i++)
    {
        scanf("%d", &mblcks[i].size);
        mblcks[i].pos = i+1;
    }
    printf("Enter the size of the processes:\n");
    for(i=0;i<nproc;i++)
    {
        scanf("%d", &proc[i]);
    }
    for(i=0;i<nproc;i++)
    {
        flag = 0;
        for(j=0;j<nblk;j++)
        {
            if(proc[i]<=mblcks[j].size && flag == 0)
            {
                printf("Process %d is allocated in memory block %d\n", i+1, mblcks[j].pos);
                mblcks[j].size = mblcks[j].size - proc[i];
                flag = 1;
            }
        }
        if(flag==0)
        {
            printf("Process %d can not be allocated in any of the blocks!\n");
            break;
        }
    }
}