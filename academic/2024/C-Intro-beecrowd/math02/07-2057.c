//https://judge.beecrowd.com/pt/problems/view/2057

#include <stdio.h>

int main () {
    float a, b, c, p, area;
    scanf("%f%f%f", &a, &b, &c);
    p = a+b+c;
    area = ( (a+b) * c) / 2;

    a < (b + c) && b < (a + c) && c < (a + b)?
        printf("Perimetro = %.1f\n", p):            //if
            printf("Area = %.1f\n", area);          //else

    return 0;
}