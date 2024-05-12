#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nop,nof,frames[10],pages[20],timestamp[10],i,j,count,fault=0;

    printf("Enter the number of pages: ");
    scanf("%d",&nop);
    printf("Enter the number of frames: ");
    scanf("%d",&nof);
    printf("Enter the page reference string: ");
    for(i=0;i<nop;i++)
    {
        scanf("%d",&pages[i]);
    }
    for(i=0;i<nof;i++)
    {
        frames[i]=-1;
        timestamp[i]=0;
    }
    printf("Page\tFrames\n");

    for(int i=0;i<nop;i++)
    {
        count=0;
        for(int j=0;j<nof;j++)
        {
            if(pages[i]!=frames[j])
            {
                count++;
            }
            else{
                timestamp[j]=i;
                break;
            }
        }
        if(i<nof){
            frames[fault]=pages[i];
            timestamp[fault]=i;
            fault++;
        }
        else if(count==nof)
        {
            int min=timestamp[0];
            for(int j=1;j<nof;j++)
            {
                if(timestamp[j]<min)
                    min=timestamp[j];
            }
            frames[min]=pages[i];
            timestamp[min]=i;
            fault++;
        }
        printf("%d\t",pages[i]);
        for(int j=0;j<nof;j++)
        {
            printf("%d\t",frames[j]);
        }
        printf("\n");
    }
    printf("Number of page faults: %d\n",fault);

}