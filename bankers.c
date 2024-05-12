#include<stdio.h>

#define proc 5
#define res 3

int main()
{
    int alloc[proc][res]={
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };
    int max[proc][res]={
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };
    int avail[res]={3,3,2};
    int f[proc]={0};
    int ans[proc];
    int ind=0;
    int need[proc][res];

    for(int i=0;i<proc;i++)
    {
        for(int j=0;j<res;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    for(int k=0;k<proc;k++)
    {
        for(int i=0;i<proc;i++)
        {
            if(f[i]==0)
            {
                int safe=1;
                for(int j=0;j<res;j++)
                    {
                        if(need[i][j]>avail[j])
                        {
                            safe=0;
                            break;
                        }
                    }
                if(safe)
                {
                    ans[ind++]  = i;
                    for(int j=0;j<res;j++)
                    {
                        avail[j]+=alloc[i][j];
                    }
                    f[i]=1;
                }
            }
            
        }
    }
    int safe_sequence = 1;
    for (int i = 0; i < proc; i++) {
        if (f[i] == 0) {
            safe_sequence = 0;
            break;
        }
    }

    // Output the result
    if (safe_sequence) {
        printf("Following is the SAFE Sequence: ");
        for (int i = 0; i < proc - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[proc - 1]);
    } else {
        printf("The system is not safe.\n");
    }

}