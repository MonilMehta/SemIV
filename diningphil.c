#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define num 5

void main()
{
    int forks[num]={1,1,1,1,1};
    bool completed[num]={false,false,false,false,false};

    int start_philosopher;

    printf("Enter the starting philosopher who wants to eat (1-5, or -1 to exit): ");
    scanf("%d", &start_philosopher);

    if(start_philosopher!=-1 && start_philosopher>=1 && start_philosopher<=num)
    {
        start_philosopher--;

        int eaten=0;
        while(eaten<num)
        {
            bool round_complete=true;
            for(int i=0;i<num;i++)
            {
                int philosopher=(start_philosopher+i)%num;
                if(!completed[philosopher])
                {
                    int left_fork=philosopher;
                    int right_fork=(philosopher+1)%num;

                    if(forks[left_fork] && forks[right_fork])
                    {
                        forks[left_fork]=0;
                        forks[right_fork]=0;

                        printf("Philosopher %d has eaten\n",philosopher+1);
                        eaten++;
                        completed[philosopher]=true;

                        start_philosopher=(philosopher+1)%num;
                        round_complete=false;
                        break;
                    }
                }
            }
            if(round_complete)
            {
                start_philosopher=(start_philosopher+1)%num;
                printf("No one more can eat in this round\n");
                for(int i=0;i<num;i++)
                {
                    forks[i]=1;
                }
            }
        }

    }
    printf("All philosophers have eaten!\n");

}