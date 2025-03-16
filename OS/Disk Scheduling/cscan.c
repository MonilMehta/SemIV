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

    for(int i=1;i<request;i++)
    {
        int j=i-1;
        int temp=req[i];
        while(j>=0 && req[j]>temp)
        {
            req[j+1]=req[j];
            j--;
        }
        req[j+1]=temp;
    }
    printf("Request Queue Sorted\n");
    for(int i=0;i<request;i++)
    {
        printf("%d  ",req[i]);
    }

    for(int i=0;i<request;i++)
    {
        if(req[i]>head)
        {
            break;
        }
        else{
            seeks=abs(req[i]);
            printf("%d\n",seeks);
        }
    }

    printf("\n - %d",track-req[0]);
    printf("\n - %d\n",track-head);

    seeks+=(abs(track-1-head)+abs(track-1));

    printf("Total number of seeks: %d\n",seeks);
}