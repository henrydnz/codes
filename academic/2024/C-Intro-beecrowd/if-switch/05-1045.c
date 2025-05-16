//https://judge.beecrowd.com/pt/problems/view/1045

#include <stdio.h>
#include <math.h>
int main() {
    float x, y, z, h, hsq, csq, csum;
    scanf ("%f%f%f", &x, &y, &z );
    // def hip and hip^2
    h=fmax(fmax(x,y),z); hsq=h*h;
    // def c1+c2 and c1^2+c2^2
    (h==x)?
        (csq=y*y+z*z, csum=y+z):
    (h==y)? 
        (csq=x*x+z*z, csum=x+z):
        (csq=x*x+y*y, csum=x+y);

    if (h<csum) {
        (hsq==csq)? 
            printf ("TRIANGULO RETANGULO\n"):
        (hsq>csq)? 
            printf ("TRIANGULO OBTUSANGULO\n"):
            printf ("TRIANGULO ACUTANGULO\n");
        if ((x==y)&&(y==z)) 
            printf ("TRIANGULO EQUILATERO\n");
        else if ((x==y)||(x==z)||(y==z)) 
            printf ("TRIANGULO ISOSCELES\n");
    } else printf ("NAO FORMA TRIANGULO\n");

    return 0;
}