#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid,arrival,completion,burst,waiting,turnaround,completed,r_burst;
    int inQueue;
};
struct process pq[10];

int q[30],front=-1,rear=-1;

void enqueue(int pid){
    if(rear==29)
        printf("Queue is full\n");
    else{
        if(front==-1)
            front=0;
        rear++;
        q[rear]=pid;
    }
}
int dequeue()
{
    int val;
    if(front==-1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        val=q[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            front++;
    }
    return val;
}

int main()
{
    int clock=0,total,completed=0,timeQuantum;
    float avgTAT=0,avgWT=0;
    
    printf("Enter the number of processes : ");
    scanf("%d",&total);
    printf("Enter the time quantum : ");
    scanf("%d",&timeQuantum);

    for (int i = 0; i < total; i++) {
        printf("Enter process id, arrival time, burst time : ");
        scanf("%d%d%d", &pq[i].pid, &pq[i].arrival, &pq[i].burst);
        pq[i].r_burst = pq[i].burst;
        pq[i].completed = 0;
        pq[i].inQueue = 0;
    }

    clock = pq[0].arrival;
    enqueue(0);
    pq[0].inQueue = 1;

    while(completed<total)
    {
        int process=dequeue();
        if(process==-1)
            break;
        int executeTime = (pq[process].r_burst > timeQuantum) ? timeQuantum : pq[process].r_burst;
        clock+=executeTime;
        pq[process].r_burst-=executeTime;
        printf("--P%d--", pq[process].pid);

        for(int i=0;i<total;i++)
        {
            if(pq[i].arrival<=clock && pq[i].completed!=1 && pq[i].inQueue!=1 && i!=process)
            {
                enqueue(i);
                pq[i].inQueue=1;
            }
        }
        if (pq[process].r_burst > 0) {
            enqueue(process);
        } else {
            pq[process].completion = clock;
            pq[process].turnaround = pq[process].completion - pq[process].arrival;
            pq[process].waiting = pq[process].turnaround - pq[process].burst;
            completed++;
            pq[process].inQueue = 0;
        }
    }
    printf("\nId\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < total; i++) {
        avgTAT += pq[i].turnaround;
        avgWT += pq[i].waiting;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pq[i].pid, pq[i].arrival, pq[i].burst, pq[i].completion, pq[i].turnaround, pq[i].waiting);
    }
    avgTAT /= total;
    avgWT /= total;
    printf("Avg TAT : %.2f, Avg WT : %.2f\n", avgTAT, avgWT);

}