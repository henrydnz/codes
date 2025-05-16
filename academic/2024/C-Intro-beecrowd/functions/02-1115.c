//https://judge.beecrowd.com/pt/problems/view/1115

#include <stdio.h>

int x, y;

void verif() {
    if ((x>0)&&(y>0)) printf ("primeiro\n");
    if ((x>0)&&(y<0)) printf ("quarto\n");
    if ((x<0)&&(y>0)) printf ("segundo\n");
    if ((x<0)&&(y<0)) printf ("terceiro\n");
}

int main() {
    while (scanf("%d%d",&x,&y)&&(x&&y)) verif();
    return 0;
}

