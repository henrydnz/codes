//https://judge.beecrowd.com/pt/problems/view/1557

#include <stdio.h>

#define MAX 100

void read(int m[][MAX], int sz) {
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++) 
            scanf("%d", &m[i][j]);
}

int subMxSum(int m[][MAX], int key) {
    return m[key][key] + m[key][key+1] + m[key+1][key] + m[key+1][key+1];
}

int subdivMx(int m[][MAX], int sz, int repSum) {
    for(int i = 0; i < sz/2; i++)
        if(subMxSum(m,i*2)!=repSum) return 0;
    return 1;
}

int main() {
    int m[MAX][MAX], sz, repSum;
    scanf("%d", &sz);
    read(m,sz);
    repSum = subMxSum(m,0);
    if(subdivMx(m,sz,repSum)) printf("SIM - %d\n", repSum);
    else printf("NAO\n");
    return 0;
}