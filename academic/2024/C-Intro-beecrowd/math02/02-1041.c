//https://judge.beecrowd.com/pt/problems/view/1041

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    float x, y;
    scanf("%f %f", &x, &y);
    !x && !y ? printf("Origem\n") :         // x0 e y0
    !x && y ? printf("Eixo Y\n") :          // x0  
    !y && x ? printf("Eixo X\n") :          // y0
    (x > 0) && (y > 0) ? printf("Q1\n") :   // pos pos
    (x < 0) && (y > 0) ? printf("Q2\n") :   // neg pos
    (x < 0) && (y < 0) ? printf("Q3\n") :   // neg neg
    printf("Q4\n");                         // pos neg

    return 0;
}