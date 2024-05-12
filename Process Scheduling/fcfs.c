#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid,arrival,completion,burst,waiting,turnaround;
};
struct process pq[10];

int main(){
    int total,clock=0;
    struct process temp;
    float avgTAT=0,avgWT=0;

    printf("FCFS Scheduling : ");
    printf("Enter number of processes : ");
    scanf("%d",&total);
    
    for(int i=0;i<total;i++)
    {
        printf("Enter process id, arrival time, burst time : ");
        scanf("%d%d%d",&pq[i].pid,&pq[i].arrival,&pq[i].burst);
    }
    for(int i=0;i<total;i++)
    {
        int j=i-1;
        temp=pq[i];
        while(j>=0 && temp.arrival<pq[j].arrival)
        {
            pq[j+1]=pq[j];
            j--;
        }
        pq[j+1]=temp;
    }
    clock=pq[0].arrival;
    for(int i=0;i<total;i++)
    {
        pq[i].completion=clock+pq[i].burst;
        clock+=pq[i].burst;
        pq[i].turnaround=pq[i].completion-pq[i].arrival;
        pq[i].waiting=pq[i].turnaround-pq[i].burst;
    }

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<total; i++){
        avgTAT += pq[i].turnaround;
        avgWT += pq[i].waiting;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pq[i].pid, pq[i].arrival, pq[i].burst, pq[i].completion, pq[i].turnaround, pq[i].waiting);
    }

    printf("Gantt Chart :\n");

    for(int i=0;i<total;i++)
    {
        for(int j;j<pq[i].burst;j++)
        {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");
    for(int i=0;i<total;i++)
    {
        for(int j;j<pq[i].burst;j++)
        {
            printf(" ");
        }
        printf("P%d",pq[i].pid);
        for(int j;j<pq[i].burst;j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("|");
    printf("\n");
    for(int i=0;i<total;i++)
    {
        for(int j;j<pq[i].burst;j++)
        {
            printf("--");
        }
        printf(" ");
    }
}