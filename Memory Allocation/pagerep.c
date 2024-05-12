#include<stdio.h>
#include<stdlib.h>

void firstFit(int block[],int m,int process[],int n)
{
    int allocation[5];
    for(int i=0;i<m;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(block[j]>=process[i])
            {
                allocation[i]=j;
                block[j]-=process[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]!=-1)
        {
            printf("%d\n",allocation[i]+1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }
}
void worstFit(int block[],int m,int process[],int n)
{
    int allocation[5];
    int worst=-1;
    for(int i=0;i<m;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        worst=-1;
        for(int j=0;j<m;j++)
        {
            if(block[j]>=process[i])
            {
                if(worst==-1)
                    worst=j;
                else{
                    if(block[worst]<block[j])
                        worst=j;
                }
            }
        }
        if(worst!=-1)
        {
            allocation[worst]=i;
            block[worst]-=process[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]!=-1)
        {
            printf("%d\n",allocation[i]+1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }
}
void nextFit(int block[],int m,int process[],int n)
{
    int allocation[5];
    int j=0,j1=0;
    for(int i=0;i<m;i++)
    {
        allocation[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        j1=0;
        while(j<m && j1<m)
        {
            if(block[j]>=process[i])
            {
                allocation[i]=j;
                block[j]-=process[i];
                break;
            }
            j1++;
            j=(j+1)%m;
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(allocation[i]!=-1)
        {
            printf("%d\n",allocation[i]+1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }
}

int main()
{
    int block[]={100,500,200,300,400};
    int process[]={100,300,300,200};
    int m=sizeof(block)/sizeof(block[0]);
    int n=sizeof(process)/sizeof(process[0]);
    // firstFit(block,m,process,n);
    // worstFit(block,m,process,n);
    nextFit(block,m,process,n);
    return 0;
}
