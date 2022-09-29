//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing disk sheduling using FCFS

#include<stdio.h>
#include<stdlib.h>

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
    //traversing from initial head position to highest I/O request position
    for(i=0;i<nreq;i++)
    {
        tothdmov += abs(arr[i]-currentpos);
        printf("       %d     \n", abs(arr[i]-currentpos));
        printf("%d--------->%d\n", currentpos, arr[i]);
        currentpos = arr[i];
    }
    printf("The total head movement=%d\n", tothdmov);
}