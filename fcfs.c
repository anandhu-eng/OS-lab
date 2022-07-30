//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing FCFS CPU sheduling

#include<stdio.h>

//defining structure
struct modal
{
    int pno;
    int at;
    int bt;
    int tat;
    int wt;
};


int main()
{
    int n, i, complttime = 0; 
    float avgtat = 0, avgwt = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    struct modal arr[n];
    for(i=0;i<n;i++)
    {
        arr[i].pno = i+1;
    }
    printf("Enter the arrival time of the processes:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i].at);
    }
    complttime = arr[0].at;
    printf("Enter the burst time of the processes:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i].bt);
    }
    for(i=0;i<n;i++)
    {
        complttime = complttime+arr[i].bt;
        arr[i].tat = complttime - arr[i].at;
        arr[i].wt = arr[i].tat - arr[i].bt;
        avgtat += arr[i].tat;
        avgwt += arr[i].wt;
    }
    printf("Process no \t Arrival time \t Burst time \t Turn around time \t Waiting time\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t\t%d\t\t%d \t\t %d \t\t\t%d\n",arr[i].pno, arr[i].at, arr[i].bt, arr[i].tat, arr[i].wt );
    }
    avgtat = avgtat/n;
    avgwt = avgwt/n;
    printf("Average waiting time=%f\n", avgwt);
    printf("Average turn around time=%f\n", avgtat);
}