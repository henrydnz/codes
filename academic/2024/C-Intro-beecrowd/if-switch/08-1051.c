//https://judge.beecrowd.com/pt/problems/view/1050

#include <stdio.h>

int main() {

    float x, i=0;
    scanf ("%f", &x);

    if (x>4500) 
        i=(x-4500)*0.28+350;
    else if (x>3000) 
        i=(x-3000)*0.18+80;
    else if (x>2000)
        i=(x-2000)*0.08;
    else 
        printf ("Isento\n");

    if (i) printf ("R$ %.2f\n", i);

    return 0;
}