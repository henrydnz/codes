//https://judge.beecrowd.com/pt/problems/view/1014

#include <stdio.h>

int main() 
{
    float x, y;
    scanf("%f %f", &x, &y);
    printf("%.3f km/l\n", x / y);

    return 0;
}