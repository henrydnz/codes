//https://judge.beecrowd.com/pt/problems/view/1365

#include <stdio.h>

#define MAX 1e6

int contains(int array[], int size, int x) {
    for(int i = 0; i < size; i++) 
        if(array[i] == x) return 1;
    return 0;
}

void readFilter(int v[], int items, int* size) {
    *size = 0;
    while(items--) {
        int x; 
        scanf("%d", &x);
        if (!contains(v, *size, x)) {
            v[*size] = x;
            (*size)++;
        }
    }
}

void show(int v[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d\n", v[i]);
}

int main() {
    int items, size; 
    scanf("%d", &items);
    int v[items];

    readFilter(v, items, &size);
    show(v, size);

    return 0;
}