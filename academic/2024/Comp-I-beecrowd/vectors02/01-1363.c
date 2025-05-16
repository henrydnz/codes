//https://judge.beecrowd.com/pt/problems/view/1363

#include <stdio.h>
#include <math.h>

void read(int array[], int size) {
    for(int i = size-1; i>=0; i--)
        scanf("%d", &array[i]);
    for(int i = size; i<10; i++)
        array[i] = 0;
}

void convert(int array[], double* var) {
    for(int i = 0; i<10; i++) 
        *var += array[i] * pow(10, i);
}

int main() {
    int arr1[10], arr2[10], size;
    double a=0, b=0;

    scanf("%d", &size);
    read(arr1, size); 
    read(arr2, size);
    convert(arr1, &a); 
    convert(arr2, &b);
    
    printf("%.0lf", a+b);
    return 0;
}