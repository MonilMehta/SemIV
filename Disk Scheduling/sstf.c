#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int req[20],isVisited[20];

int getMin(int head,int request)
{
    int min=0;
    for(int i=0;i<request;i++)
    {
        if(isVisited[i]!=1)
        {
            min=i;
            break;
        }
    }
    for(int i=min;i<request;i++)
    {
        if(isVisited[i]!=1 && (abs(head-req[i])<abs(head-req[min])))
            min=i;
    }
    return min;
}

int main()
{
    int req[20];
    int track,request,head,seeks=0,completed=0;
    printf("Enter the number of tracks: ");
    scanf("%d",&track);
    printf("Enter the number of requests: ");
    scanf("%d",&request);

    printf("Enter the request queue: ");
    for(int i=0;i<request;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d",&head);

    for(int i=0;i<request;i++)
    {
        isVisited[i]=0;
    }
    
    while(completed<request)
    {
        int a=getMin(head,request);
        seeks+=abs(head-req[a]);
        isVisited[a]=1;
        completed++;
        head=req[a];
    }
    printf("Total number of seeks: %d\n",seeks);
}