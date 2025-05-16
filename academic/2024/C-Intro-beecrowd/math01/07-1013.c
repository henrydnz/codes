//https://judge.beecrowd.com/pt/problems/view/1013


#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", max(a, max(b, c)));
    return 0;
}