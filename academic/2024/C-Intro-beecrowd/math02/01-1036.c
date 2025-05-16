//https://judge.beecrowd.com/pt/problems/view/1036

#include <stdio.h>
#include <math.h>

int main() 
{
    double a, b, c, d, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);

    d = pow(b, 2) - 4 * a * c;

    d < 0 || a == 0 ? printf("Impossivel calcular\n") : (
        x1 = (-b + sqrt(d)) / (2 * a),
        x2 = (-b - sqrt(d)) / (2 * a),
        printf("R1 = %.5lf\n", x1),
        printf("R2 = %.5lf\n", x2)
    );

    return 0;
}