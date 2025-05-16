//https://judge.beecrowd.com/pt/problems/view/1187

#include <stdio.h>

#define MAX 12

void read(double m[][MAX]) {
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            scanf("%lf", &m[i][j]);
}

void sum(double m[][MAX], double* ans) {
    *ans = 0;
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            if((j > 11 - i) && (j > i)) 
                *ans += m[i][j];
}

int main() {
    char op;
    double m[MAX][MAX], ans;
    scanf("%c", &op);
    read(m);

    sum(m, &ans);
    if(op == 'M') ans/=30;
    printf("%.1lf\n", ans);

    return 0;
}

