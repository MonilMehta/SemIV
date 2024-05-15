#include <stdio.h>

int A[] = {9,5,7,3,6,2,1,8,4};

void insertionsort(int A[], int n){

    for (int i = 1; i < n; i++)        
    {   
         int temp = A[i];
         int j = i-1;
        while (j >= 0 && A[j] > temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;           
    }
    for (int l = 0; l < n; l++)
    {
        printf("%d",A[l]);
    }
    
}

void main(){
    insertionsort(A,9);
}