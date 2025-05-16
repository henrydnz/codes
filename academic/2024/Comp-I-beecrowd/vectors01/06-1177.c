//https://judge.beecrowd.com/pt/problems/view/1177

#include <stdio.h>

#define MAX 1000

void fill(int N[], int t) {
    int aux = 0;
    for(int i = 0; i < MAX; i++) {
        N[i] = aux;
        aux++;
        if(aux>=t)
            aux = 0;
    }
}

void show(int N[]) {
    for(int i = 0; i < MAX; i++)
        printf("N[%d] = %d\n", i, N[i]);
}

int main() {
    int N[MAX];
    int t; 
    scanf("%d", &t);
    fill(N, t);
    show(N);

    return 0;
}