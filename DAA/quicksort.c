#include<stdio.h>
#include<time.h>

int arr[10000];
int quick(int beg,int end)
{
    int i=beg,j=end,loc=beg,temp,flag=0;
    while(flag!=1)
    {
        while(arr[loc]<=arr[j] && loc!=j)
            j--;
        if(loc==j)
            flag=1;
        else if(arr[loc]>arr[j])
        {
            temp=arr[loc];
            arr[loc]=arr[j];
            arr[j]=temp;
        }
        if(flag!=1)
        {
            while(arr[loc]>=arr[i] && loc!=i)
                i++;
            if(loc==i)
                flag=1;
            else if(arr[loc]<arr[i])
            {
                temp=arr[loc];
                arr[loc]=arr[i];
                arr[i]=temp;
            }
        }
    }
    return loc;
}
void quicksort(int beg,int end)
{
    int loc;
    if(beg<end){
        loc=quick(beg,end);
        quick(beg,loc-1);
        quick(loc+1,end);

    }
}
int main()
{
    int time;
    clock_t start,end;
    for(int i=0;i<10000;i++)
    {
        long int no=rand();
        arr[i]=no;
    }
    int n=10000;
    start=clock();
    quicksort(0,n-1);
    end=clock();
    time=end-start;
    printf("\n Avg Time is: %d",time);
    start=clock();
    quicksort(0,n-1);
    end=clock();
    time=end-start;
    printf("\n Best Time is: %d",time);

    // for(int i=0;i<15;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    return 0;
    
}