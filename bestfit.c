//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing bestfit memory allocation

#include<stdio.h>

struct details
{
    int pos;
    int size;
};

void sort(struct details* arr, int n)
{
    int i, j, temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j].size>arr[j+1].size)
            {
                temp = arr[j].size;
                arr[j].size = arr[j+1].size;
                arr[j+1].size = temp;
                temp = arr[j].pos;
                arr[j].pos = arr[j+1].pos;
                arr[j+1].pos = temp;
            }
        }
    }
}

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
    sort(mblcks, nblk);
    for(i=0;i<nblk;i++)
    {
        printf("%d\n", mblcks[i].size);
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
        sort(mblcks, nblk);
    }
}