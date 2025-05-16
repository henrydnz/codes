//https://judge.beecrowd.com/pt/problems/view/1038

#include <stdio.h>

int main() {
    
    float x, y, z;
    scanf("%f%f", &x, &y);


    if (x == 1) z=y*4.0;
    else if (x == 2) z=y*4.5;
    else if (x == 3) z=y*5.0;
    else if (x == 4) z=y*2.0;
    else if (x == 5) z=y*1.5;

    printf("Total: %.2f\n", z); 

    
 
    return 0;
}