//Name: Anandhu S
//Roll No: 211
//Class: R4-A
//Program: Implementing Round robin scheduling

//NOTE: output wrong!

#include<stdio.h>
  
struct table
{
    int pno,at, bt, backupbt, tat, wt;
};

int main()  
{
    int i, j, n, quant, temp, y, complttime;
    int avg_wt = 0, avg_tat = 0;  
    printf("Enter the total number of process in the system:");  
    scanf("%d", &n);    
    y = n;
    struct table proc[n];
    for(i=0; i<n; i++)  
    {
        printf("Enter the arrival time of process %d:", i+1);    
        scanf("%d", &proc[i].at);  
        printf("Enter the birst time of process %d:", i+1); 
        scanf("%d", &proc[i].bt);  
        proc[i].backupbt = proc[i].bt;
        proc[i].pno = i+1;
    }  
    printf("Enter the Time Quantum for the process: ");  
    scanf("%d", &quant); 
    //sort based on arrival time 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(proc[j].at>proc[j+1].at)
            {
                temp = proc[j].pno;
                proc[j].pno = proc[j+1].pno;
                proc[j+1].pno = temp;
                temp = proc[j].bt;
                proc[j].bt = proc[j+1].bt;
                proc[j+1].bt = temp;
                temp = proc[j].backupbt;
                proc[j].backupbt = proc[j+1].backupbt;
                proc[j+1].backupbt = temp;
                temp = proc[j].at;
                proc[j].at = proc[j+1].at;
                proc[j+1].at = temp;
            }
        }
    }
    complttime = proc[0].at;
    while(y!=0)
    {
        for(j=0;j<n;j++)
        {
            if(proc[j].at<=complttime && proc[j].bt!=0)
            {
                complttime += proc[j].bt;
                if(proc[j].bt-quant<=0)
                {
                    proc[j].bt = 0;
                    proc[j].tat = complttime - proc[j].at;
                    proc[j].wt = proc[j].tat - proc[j].backupbt;
                    avg_tat += proc[j].tat;
                    avg_wt += proc[j].wt;
                    y--;
                    printf("%d", proc[j].pno);
                }
                else
                {
                    proc[j].bt -= quant;
                    printf("%d", proc[j].pno);
                }
            }
            //printf("%d", y);
        }
    }
    printf("Process no\tBurst time\tturnaround time\twaiting time\n");
    for(i=0;i<n;i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d\n", proc[i].pno, proc[i].backupbt, proc[i].tat, proc[i].wt);
    }
    printf("Total waiting time:%d\n", avg_wt);
    printf("Average waiting time:%f\n", (float)avg_wt/n);
    printf("Total turn around time:%d\n", avg_tat);
    printf("Average turn around time:%f\n", (float)avg_tat/n);
}