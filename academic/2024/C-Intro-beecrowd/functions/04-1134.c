//https://judge.beecrowd.com/pt/problems/view/1134

#include <stdio.h>

int x, a, b, c;

int main() {
    while((scanf("%d", &x)) && (x!=4)) {
        if(x==1) a++;
        if(x==2) b++;
        if(x==3) c++;
    }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", a);
    printf("Gasolina: %d\n", b);
    printf("Diesel: %d\n", c);
    return 0;
}