#include <stdio.h>
#include <string.h>

int pi[10];

void cmp(char *P) {
    int k = 0;
    pi[0] = 0;
    int n = strlen(P);
    for (int i = 1; i < n; i++) {
        while (k != 0 && P[k] != P[i]) {
            k = pi[k - 1];
        }
        if (P[k] == P[i]) {
            k++;
        }
        pi[i] = k;
    }
}

void KMP(char *T, char *P) {
    int m = strlen(T);
    int n = strlen(P);
    cmp(P);
    int q = 1;
    for (int i = 0; i < m; i++) {
        while (q != 0 && P[q] != T[i]) {
            q = pi[q];
        }
        if (P[q] == T[i]) {
            q++;
        }
        if (q == n) {
            printf("Pattern at %d\n", i-n+1);
            q = pi[q];
        }
    }
}

int main() {
    KMP("abcdbcebce", "bceb");
    return 0;
}