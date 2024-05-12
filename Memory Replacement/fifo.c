#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nop,nof,frames[10],pages[20],i,j,count,fault=0,frameHead=0;
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
    }
    printf("Page\tFrames\n");
    for(int i=0;i<nop;i++)
    {
        count=0;
        for(j=0;j<nof;j++)
        {
            if(pages[i]==frames[j])
            {
                count++;
            }
            else{
                break;
            }
        }
        if(i<nof)
        {
            frames[fault++]=pages[i];   
        }
        else if(count==nof)
        {
            frames[frameHead]=pages[i];
            frameHead=(frameHead+1)%nof;
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