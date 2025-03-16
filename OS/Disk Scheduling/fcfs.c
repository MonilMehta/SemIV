#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int req[20];
    int track,request,head,seeks=0;
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
        seeks+=abs(head-req[i]);
        head=req[i];
    }
    printf("Total number of seeks: %d\n",seeks);
}