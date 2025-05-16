//https://judge.beecrowd.com/pt/problems/view/1174

#include <stdio.h>

int main() {
    int A[100];
    for(int i = 0; i < 100; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < 100; i++)
        if (A[i] <= 0) 
            printf("A[%d] = %d\n", i, A[i]);

    return 0;
}