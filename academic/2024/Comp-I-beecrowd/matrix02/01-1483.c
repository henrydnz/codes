//https://judge.beecrowd.com/pt/problems/view/1483

#include <stdio.h>
#include <math.h>

#define MAX 100

void read(int m[][MAX], int a, int b) {
    for(int i = 0; i < a; i++) 
        for(int j = 0; j < b; j++)
            scanf("%d", &m[i][j]);
}

void check(int m[][MAX], int a, int b, int* ans) {
    *ans = 0;
    for(int i = 0; i < a; i++) {
        int aux = 0;
        for(int j = 0; j < b; j++)
            aux += abs(m[i][j]%2);
        *ans += !aux;
    } 
}

int main() {
    int m[MAX][MAX], a, b, ans;
    scanf("%d %d", &a, &b);
    read(m, a, b);
    check(m, a, b, &ans);
    printf("%d\n", ans);
    return 0;
}