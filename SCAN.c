//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing disk sheduling using SCAN

#include<stdio.h>

int main()
{
    int initpos, nreq, i, j, temp, currentpos, secpos = -1, tothdmov = 0;
    printf("Enter the initial position of the head:");
    scanf("%d", &initpos);
    currentpos = initpos;
    printf("Enter the number of I/O requests:");
    scanf("%d", &nreq);
    int arr[nreq];
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
    //comming back from highest I/O request position
    for(i=secpos;i>=0;i--)
    {
        tothdmov += currentpos-arr[i];
        printf("       %d     \n", currentpos-arr[i]);
        printf("%d--------->%d\n", currentpos, arr[i]);
        currentpos = arr[i];
    }
    printf("The total head movement=%d\n", tothdmov);
}