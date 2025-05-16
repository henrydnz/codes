//https://judge.beecrowd.com/pt/problems/view/1176

#include <stdio.h>

#define MAX 61

void setFib(double fib[]) {
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i < MAX; i++)
        fib[i] = fib[i-1] + fib[i-2];
}


void ans() {
    double fib[MAX];
    setFib(fib);
    int t, q;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &q);
        printf("Fib(%d) = %.0lf\n", q, fib[q]);
    }
}

int main() {
    ans();
    return 0;
}