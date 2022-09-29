//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing disk sheduling using CSCAN

#include<stdio.h>

int main()
{
    int initpos, nreq, i, j, temp, currentpos, maxpos, secpos = -1, tothdmov = 0;
    printf("Enter the initial position of the head:");
    scanf("%d", &initpos);
    currentpos = initpos;
    printf("Enter the number of I/O requests:");
    scanf("%d", &nreq);
    int arr[nreq];
    printf("Enter the maximum position:");
    scanf("%d", &maxpos);
    printf("Enter the I/O requests:");
    for(i=0;i<nreq;i++)
    {
        scanf("%d", &arr[i]);
    }
    //sorting the array
    for(i=0;i<nreq;i++)
    {
        for(j=0;j<nreq-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    //traversing from initial head position to highest I/O request position
    for(i=0;i<nreq;i++)
    {
        if(arr[i]<initpos)
        {
            secpos = i;
        }
        else if (arr[i]>initpos)
        {
            tothdmov += arr[i]-currentpos;
            printf("       %d     \n", arr[i]-currentpos);
            printf("%d--------->%d\n", currentpos, arr[i]);
            currentpos = arr[i];
        }
    }
    //travelling to the end of the disk
    if(arr[i]!=maxpos)
    {
        tothdmov += maxpos-currentpos;
        printf("       %d     \n", maxpos-currentpos);
        printf("%d--------->%d\n", currentpos, maxpos);
        currentpos = maxpos;
    }
    //travelling to the begining of the disk
    tothdmov += maxpos;
    printf("       %d     \n", maxpos);
    printf("%d--------->%d\n", currentpos, 0);
    currentpos = 0;
    //traversing fromm 0th position
    for(i=0;i<=secpos;i++)
    {
        tothdmov += arr[i]-currentpos;
        printf("       %d     \n", arr[i]-currentpos);
        printf("%d--------->%d\n", currentpos, arr[i]);
        currentpos = arr[i];
    }
    printf("The total head movement=%d\n", tothdmov);
}