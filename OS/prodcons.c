#include<stdio.h>

int x=0,mutex=1,empty=5,full=0;

void producer()
{
    mutex--;
    full++;
    x++;
    empty--;
    printf("Producer produces item %d\n",x);
    mutex++;
}
void consumer()
{
    mutex--;
    empty++;
    full--;
    printf("Consumer consumes item %d\n",x);
    x--;
    mutex++;
}

int main()
{
    int choice;
    printf("1.Producer\n2.Consumer\n3.Exit\n");

    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            if(mutex==1 && full!=5)
                producer();
            else
                printf("Buffer is full\n");
            break;
        case 2:
        if(mutex==1 && full!=0)
            consumer();
        else
            printf("Buffer is empty\n");
            break;
        
        default:
            break;
        }
    }while (choice!=3);
    return 0;
}