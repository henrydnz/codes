//https://judge.beecrowd.com/pt/problems/view/2553

#include <stdio.h>

#define MAX 100

void read(int m[][MAX], int sz) {
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++)
            scanf("%d", &m[i][j]);
}

int isPerfect(int m[][MAX], int sz, int* ans) {
    int d1=0,d2=0;
    for(int i = 0; i < sz; i++) {
        int row=0,col=0;
        for(int j = 0; j < sz; j++) {
            row+=m[i][j];
            col+=m[j][i];
            d1+=(i==j)?m[i][j]:0;
            d2+=(i==sz-j-1)?m[i][j]:0;
        }
        if(row!=col) return 0;
        *ans=row;
    }
    printf("d1=%d      d2=%d\n", d1, d2);
    if(((*ans!=d1)||(*ans!=d2))||d1!=d2) return 0;
    return 1;
}

int main() {
    int m[MAX][MAX], sz, ans;
    scanf("%d", &sz);
    read(m,sz);
    if(!isPerfect(m,sz,&ans)) ans = -1;
    printf("%d\n", ans); 
    return 0;
}