#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid,arrival,completion,burst,waiting,turnaround,completed,priority;
};
struct process pq[10];

int findPri(int clock,int total)
{
    int min=0;
    for(int i=0;i<total;i++)
    {
        if(pq[i].arrival<=clock && pq[i].completed==0)
        {
            min=i;
            break;
        }
    }
    for(int i=min;i<total;i++)
    {
        if(pq[i].arrival<=clock && pq[i].completed==0 && pq[i].priority>pq[min].priority)
            min=i;
    }
    return min;
}
int main()
{
    int total,clock=0,completed=0,j;
    struct process temp;
    float avgTAT=0,avgWT=0;

    printf("Enter the number of processes : ");
    scanf("%d",&total);

    for(int i=0;i<total;i++)
    {
        printf("Enter process id, arrival time, burst time,process priority : ");
        scanf("%d%d%d%d",&pq[i].pid,&pq[i].arrival,&pq[i].burst,&pq[i].priority);
    }
    for(int i=1;i<total;i++)
    {
        temp=pq[i];
        j=i-1;
        while(j>=0 && temp.arrival<pq[j].arrival)
        {
            pq[j+1]=pq[j];
            j--;
        }
        pq[j+1]=temp;
    }
    clock=pq[0].arrival;
    while(completed<total)
    {
        int min=findPri(clock,total);
        pq[min].completed=clock+pq[min].burst;
        pq[min].turnaround=pq[min].completed-pq[min].arrival;
        pq[min].waiting=pq[min].turnaround-pq[min].burst;
        pq[min].completed=1;
        clock+=pq[min].burst;
        completed+=1;
    }
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<total;i++)
    {
        avgTAT+=pq[i].turnaround;
        avgWT+=pq[i].waiting;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pq[i].pid,pq[i].arrival,pq[i].burst,pq[i].completed,pq[i].turnaround,pq[i].waiting);
    }

    for(int i=0;i<total;i++)
    {
        for(int j=0;j<total-i-1;j++)
        {
            if(pq[j].completion>pq[j+1].completion)
            {
                struct process temp=pq[j];
                pq[j]=pq[j+1];
                pq[j+1]=temp;
            }
        }
    }

    printf("Gantt Chart :\n");
    printf(" ");
    for (int i = 0; i < total; i++) {
        for (int t = 0; t < pq[i].burst; t++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");
    for (int i = 0; i < total; i++) {
        for (int t = 0; t < pq[i].burst - 1; t++) {
            printf(" ");
        }
        printf("P%d", pq[i].pid);
        for (int t = 0; t < pq[i].burst - 1; t++) {
            printf(" ");
        }
        printf("|");
    }
    printf("\n ");
    for (int i = 0; i < total; i++) {
        for (int t = 0; t < pq[i].burst; t++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");
    printf("Average Turnaround Time : %f\n", avgTAT/total);
    printf("Average Waiting Time : %f\n", avgWT/total);
}