//https://judge.beecrowd.com/pt/problems/view/2313

#include <stdio.h>
#include <math.h>

int main() {
    int x, y, z, h, hsq, csq, csum;
    scanf ("%d%d%d", &x, &y, &z );
    
    h = x>y? x: y; 
    h = h>z? h: z;
    hsq = h*h;
    
    (h==x)?(
        csq=y*y+z*z, 
        csum=y+z
    ):
    (h==y)? (
        csq=x*x+z*z, 
        csum=x+z
    ):(
        csq=x*x+y*y,
        csum=x+y
    );

    if (h<csum) {
        printf ("Valido-SS");
        if ((x==y)&&(y==z)) printf ("Equilatero\n");
        else if ((x==y)||(x==z)||(y==z)) printf ("Isosceles\n");
        else printf ("Escaleno\n");
        printf ("Retangulo: ");
        printf ((hsq==csq)? "S\n": "N\n");
    } else printf ("Invalido\n");

    return 0;
}