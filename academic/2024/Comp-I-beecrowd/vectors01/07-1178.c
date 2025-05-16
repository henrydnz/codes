//https://judge.beecrowd.com/pt/problems/view/1178

#include <stdio.h>

#define MAX 100

void fill(double N[], double t) {
    N[0] = t;
    for(int i = 1; i < MAX; i++)
        N[i] = N[i-1]/2;
}

void show(double N[]) {
    for(int i = 0; i < MAX; i++) {
        printf("N[%d] = %.4lf\n", i, N[i]);
    }
}

int main() {
    double N[MAX];
    double t;
    scanf("%lf", &t);
    fill(N, t);
    show(N);
    return 0;
}