//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing bankers algorithm for deadlock avoidance

#include<stdio.h>

struct resource
{
    int a;
    int b;
    int c;
};

int main()
{
    int nofp, i, j = 0, flag = 0, pos=1;
    printf("Enter the number of processes:");
    scanf("%d", &nofp);
    struct resource allocation[nofp], max[nofp], available[nofp], need[nofp];
    int index=nofp, process[nofp];
    //assigning each process flag with 0
    for(i=0;i<nofp;i++)
    {
        process[i] = 0;
    }
    //Enter values to allocation
    for(i=0;i<nofp;i++)
    {
        printf("Enter the resource allocated for process %d:", i+1);
        scanf("%d %d %d", &allocation[i].a, &allocation[i].b, &allocation[i].c);
    }
    //enter value to max
    for(i=0;i<nofp;i++)
    {
        printf("Enter the resource needed for process %d to complete:", i+1);
        scanf("%d %d %d", &max[i].a, &max[i].b, &max[i].c);
    }
    //filling the need column
    for(i=0;i<nofp;i++)
    {
        need[i].a = max[i].a - allocation[i].a;
        need[i].b = max[i].b - allocation[i].b;
        need[i].c = max[i].c - allocation[i].c;
    }
    printf("Enter the initially allocated resources:");
    scanf("%d %d %d", &available[0].a, &available[0].b, &available[0].c);
    printf("The order of process execution is:\n");
    //filling the available column
    for(i=0;i<nofp;i++)
    {
        flag = 0;
        index = nofp;
        while(index!=0)
        {
            if(process[j]==0 && flag==0)
            {
                if(need[j].a<=available[i].a && need[j].b<=available[i].b && need[j].c<=available[i].c)
                {
                    if(i+1!=nofp)
                    {
                        available[i+1].a = allocation[j].a + available[i].a;
                        available[i+1].b = allocation[j].b + available[i].b;
                        available[i+1].c = allocation[j].c + available[i].c; 
                    }
                    flag = 1;
                    process[j] = 1;
                    printf("P%d ", j);
                    break;
                }
            }
            j = (j+1)%nofp;
            index--;
        }
    }
    printf("\nAllocation\t  max \tavailable \t  need\n");
    printf("A   B    C\t A B C\tA   B   C \t A B C\n");
    for(i=0;i<nofp;i++)
    {
        printf("%d   %d    %d\t %d %d %d\t%d   %d   %d \t %d %d %d\n", allocation[i].a, allocation[i].b, allocation[i].c, max[i].a, max[i].b, max[i].c, available[i].a, available[i].b, available[i].c, need[i].a, need[i].b, need[i].c);
    }
}