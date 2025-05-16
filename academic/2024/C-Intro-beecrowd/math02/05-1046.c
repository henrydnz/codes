//https://judge.beecrowd.com/pt/problems/view/1046

#include <stdio.h>

int main() 
{
    int ini, fim, hor;
    scanf("%d %d", &ini, &fim);

    hor = ini==fim? 24: 
    ini<fim? fim-ini: 24-(ini-fim);

    printf("O JOGO DUROU %d HORA(S)", hor);  

    return 0;
}