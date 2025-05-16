//https://judge.beecrowd.com/pt/problems/view/2059

#include <stdio.h>

// 1 rouba 2 acusa = 2 ganha
// 1 rouba = 1 ganha
// 2 acusa = 1 ganha

int main() {
    int p, j1, j2, r, a;
    scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a);

    r && a ? printf("Jogador 2 ganha!") :                       // roubo e acusacao
    r || a ? printf("Jogador 1 ganha!") :                       // so roubo ou so acusacao
    ((j1 + j2) % 2) && !p ? printf("Jogador 1 ganha!") :        // impar e impar
    !((j1 + j2) % 2) && p ? printf("Jogador 1 ganha!") :        // par e par
    printf("Jogador 2 ganha!");                                 // par e impar

    printf("\n");



    return 0;
}