//https://judge.beecrowd.com/pt/problems/view/2060

#include <stdio.h>
int a, b, c, d;
void ans() {
    int n; scanf("%d", &n);
    if(!(n%2)) a++;
    if(!(n%3)) b++;
    if(!(n%4)) c++;
    if(!(n%5)) d++;
}
int main() {
    int x; scanf("%d", &x);
    while(x--) ans();
    printf("%d Multiplo(s) de 2\n", a);
    printf("%d Multiplo(s) de 3\n", b);
    printf("%d Multiplo(s) de 4\n", c);
    printf("%d Multiplo(s) de 5\n", d);
    return 0;
}