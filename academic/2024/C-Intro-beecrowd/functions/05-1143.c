////https://judge.beecrowd.com/pt/problems/view/1143

#include <stdio.h>

int sq(int x) { return x*x; }
int cb(int x) { return x*x*x; }

void ans(int x) { 
    for(int i=1;i<=x;i++) 
        printf("%d %d %d\n", i, sq(i), cb(i));
}
int main() {
    int x;
    scanf("%d", &x);
    ans(x);
    return 0;
}