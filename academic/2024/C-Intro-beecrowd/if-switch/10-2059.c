//https://judge.beecrowd.com/pt/problems/view/2059

#include <stdio.h>

int main() {

    int p, x, y, a1, a2;
    scanf ("%d%d%d%d%d", &p, &x, &y, &a1, &a2 );
    if (a1!=a2) printf ("Jogador 1 ganha!\n");
    else if (a1&&a2) printf ("Jogador 2 ganha!\n");
    else if ((x+y)%2!=p) printf("Jogador 1 ganha!\n");
    else printf("Jogador 2 ganha!\n");

    return 0;
}

