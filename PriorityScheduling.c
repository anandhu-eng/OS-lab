//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing Priority scheduling

#include <stdio.h>
#include <stdlib.h>

struct table
{
    int pno;
    int at;
    int pri;
    int btime;
    int wtime;
    int tat;
};

int main()
{
    int i,j,n, shortest_at, temp;
    int comptime, totwt = 0, tot_tat = 0;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    struct table proc[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time, arrival time and priority of process %d:", i+1);
        scanf("%d %d %d", &proc[i].btime, &proc[i].at, &proc[i].pri);
        if(i==0)
        {
            shortest_at = proc[i].at;
        }
        else
        {
            if(proc[i].at<shortest_at)
            {
                shortest_at = proc[i].at;
            }
        }
        proc[i].pno=i+1;
        proc[i].wtime=0;
    }
    comptime = shortest_at;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(proc[j].at>proc[j+1].at)
            {
                temp = proc[j].pno;
                proc[j].pno = proc[j+1].pno;
                proc[j+1].pno = temp;
                temp = proc[j].btime;
                proc[j].btime = proc[j+1].btime;
                proc[j+1].btime = temp;
                temp = proc[j].at;
                proc[j].at = proc[j+1].at;
                proc[j+1].at = temp;
                temp = proc[j].pri;
                proc[j].pri = proc[j+1].pri;
                proc[j+1].pri = temp;
            }
            else if(proc[j].at==proc[j+1].at)
            {
                if(proc[j].pri>proc[j+1].pri)
                {
                    printf("YES");
                    temp = proc[j].pno;
                    proc[j].pno = proc[j+1].pno;
                    proc[j+1].pno = temp;
                    temp =proc[j].btime;
                    proc[j].btime = proc[j+1].btime;
                    proc[j+1].btime = temp;
                    temp = proc[j].at;
                    proc[j].at = proc[j+1].at;
                    proc[j+1].at = temp;
                    temp = proc[j].pri;
                    proc[j].pri = proc[j+1].pri;
                    proc[j+1].pri = temp;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        comptime += proc[i].btime;
        proc[i].tat = comptime - proc[i].at;
        tot_tat += proc[i].tat; 
        proc[i].wtime = proc[i].tat - proc[i].btime;
        totwt += proc[i].wtime;
    }
    printf("\nprocess\t   bursttime\twaiting time\tturnaround time");
    for(i=0;i<n;i++)
    {
        printf("\n %d\t\t%d",proc[i].pno,proc[i].btime);
        printf("\t\t%d\t\t%d",proc[i].wtime,proc[i].tat);
    }
    printf("\n\n total waiting time:%d",totwt);
    printf("\n average waiting time:%f",(float)totwt/n);
    printf("\n total turnaround time:%d",tot_tat);
    printf("\n avg turnaround time:%f",(float)tot_tat/n);
}   