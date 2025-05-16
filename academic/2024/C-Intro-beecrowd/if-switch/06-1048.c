//https://judge.beecrowd.com/pt/problems/view/1048

#include <stdio.h>

int main() {

    float x,r;
    scanf ("%f", &x);

    if (x <= 400) r=15;
    else if (x <=800) r=12;
    else if (x <=1200) r=10;
    else if (x <=2000) r=7; 
    else r=4;

    printf ("Novo salario: %.2f\n", x+x*(r/100));
    printf ("Reajuste ganho: %.2f\n", x*(r/100));
    printf ("Em percentual: %d \%\n", (int) r);

    return 0;
}