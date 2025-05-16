//https://judge.beecrowd.com/pt/problems/view/1556

#include <stdio.h>
#include <math.h>

void read(double v[], int size) {
    for(int i = 0; i < size; i++)
        scanf("%lf", &v[i]);
}

void vecShortener(double v1[], double v2[], int size, int* newSize, int g) {
    *newSize = ceil((float) size/g);        // divide arredonda pra cima
    for(int i = 0; i < *newSize; i++) {
        double aux1 = 0, aux2 = 0;
        for(int j = g*i; j < g*(i+1); j++)
            if(j < size) {
                aux1 += v1[j];
                aux2++;
            }
        v2[i] = aux1/aux2;
    }
}

void show(double v[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%.2lf\n", v[i]);
    }
}

int main() {
    int size, newSize, g; 
    scanf("%d", &size);
    double v1[size], v2[size];
    read(v1, size);
    scanf("%d", &g);
    vecShortener(v1, v2, size, &newSize, g);
    show(v2, newSize);
    return 0;
}