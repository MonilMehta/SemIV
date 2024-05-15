#include <stdio.h>
#define n 7

int x[n], m = 35, w[n] = {15,7,20,5,18,10,12};

int SumOfSubset(int i, int s, int r){
    //left node
    x[i] = 1;
    if((s + w[i]) == m){
        printf("\n");
        for (int j=0; j<=i; j++){
            printf("%d\t", w[j]*x[j]);
        }
        for (int j=i+1; j<n; j++){
            printf("%d\t", 0);
        }
    }
    else if (s + w[i] + w[i+1] <= m){
        SumOfSubset(i+1, s+w[i], r-w[i]);
    }

    //right node
    if((s + w[i+1]) <= m && (s + r - w[i]) >= m){
        x[i] = 0;
        SumOfSubset(i+1,s,r-w[i]);
    }
}

void main(){
    int s=0,r=0;
    for (int i=0; i<n; i++){
        r += w[i];
        x[i] = 0;
    }
    SumOfSubset(0,s,r);
}