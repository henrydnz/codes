//https://judge.beecrowd.com/pt/problems/view/1485

#include <stdio.h>

#define MAX 100

void read(int m[][MAX], int a, int b) {
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            scanf("%d", &m[i][j]);
}

int case_1(int m[][MAX], int sz) {
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++) {
            if((i==j)&&(!m[i][j])) return 0;
            if((i!=j)&&(m[i][j])) return 0;
        }
    return 1;
}

int case_2(int m[][MAX], int sz) {
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++) {
            if((i+j==sz-1)&&(!m[i][j])) return 0;
            if((i+j!=sz-1)&&(m[i][j])) return 0;
        }
    return 1;
}

int case_3(int m[][MAX], int a, int b) {
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++) {
            if((((!i)||(i==a-1))||((!j)||(j==b-1)))&&!m[i][j]) return 0;
            if(((i&&j)&&((i>a-1)&&(j<b-1)))&&(m[i][j])) return 0;
        }
    return 1;
}

int check(int m[][MAX], int a, int b) {
    if(a==b) {
        if(case_1(m,a)) return 1;
        if(case_2(m,a)) return 2;
    }
    if(case_3(m,a,b)) return 3;
    return 0;
}

int main() {
    int m[MAX][MAX], a, b;
    scanf("%d %d", &a, &b);
    read(m, a, b);
    printf("%d\n", check(m, a, b));
    return 0;
}