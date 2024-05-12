#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid,arrival,completion,burst,waiting,turnaround,r_burst,start;
    int comp;
};

struct process pq[10];

int findMin(int clock,int total)
{
    int min=0;

    for(int i=0;i<total;i++)
    {
        if(pq[i].arrival<=clock && pq[i].comp==0)
        {
            min=i;
            break;
        }
    }
    for(int i=min;i<total;i++)
    {
        if(pq[i].arrival<=clock && pq[i].comp==0 && pq[i].r_burst<pq[min].r_burst)
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
        printf("Enter process id, arrival time, burst time : ");
        scanf("%d%d%d",&pq[i].pid,&pq[i].arrival,&pq[i].burst);
        pq[i].comp=0;
        pq[i].r_burst=pq[i].burst;
        pq[i].start=-1;
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
        int min=findMin(clock,total);
        if(pq[min].start==-1)
        {
            pq[min].start=clock;
        }
        pq[min].r_burst--;
        clock++;
        if(pq[min].r_burst==0)
        {
            pq[min].completion=clock;
            pq[min].comp=1;
            completed+=1;
            pq[min].turnaround = pq[min].completion - pq[min].arrival;
            pq[min].waiting = pq[min].turnaround - pq[min].burst;
        }
    }
    printf("\n");
    
    printf("Id\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<total; i++){
        avgTAT += pq[i].turnaround;
        avgWT += pq[i].waiting;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, pq[i].arrival, pq[i].burst, pq[i].completion, pq[i].turnaround, pq[i].waiting);
    }
    avgTAT /= total; 
    avgWT /= total; 
    printf("Avg TAT : %.2f, Avg WT : %.2f", avgTAT, avgWT);
}