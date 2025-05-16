//https://judge.beecrowd.com/pt/problems/view/1044

#include <stdio.h>

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    !(x%y) || !(y%x)? printf("Sao Multiplos\n"): printf("Nao sao Multiplos\n");
    
}