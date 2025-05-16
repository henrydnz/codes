//https://judge.beecrowd.com/pt/problems/view/1149

#include <stdio.h>
int x, n, sum;
void ans() { 
    scanf("%d", &x);
    while(scanf("%d", &n)) if(n>0) break;
    while(n--) sum+=n+x;
    printf("%d\n", sum);
}
int main() {
    ans();
    return 0;
}