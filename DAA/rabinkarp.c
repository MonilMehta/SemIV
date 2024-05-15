#include <stdio.h>
#include <string.h>
#include<math.h>

int val(char x){
    return ((int)x) - 96;
}

void Rabin(char *T, char *P){
    int m = strlen(T);
    int n = strlen(P);
    int t=0, p=0;
    for(int i=0; i<n; i++){
        p = p*10 + val(P[i]);
        t = t*10 + val(T[i]);
    }
    for(int i=0; i<=m-n; i++){
        if (p == t){
            printf("Pattern at %d\n", i);
        }
        if (i < m-n){
            t = (t - val(T[i])*pow(10, n-1))*10 + val(T[i+n]);
        }
    }
}

int main(){
    Rabin("malayalam","al");
    return 0;
}