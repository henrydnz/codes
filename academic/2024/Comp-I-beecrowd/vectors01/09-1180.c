//https://judge.beecrowd.com/pt/problems/view/1180

#include <stdio.h>

#define INF 1e6

int min(int x, int y) {
    return (x<y)? x: y;
}

void fill(int arr[], int size) {
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
}

void lower(int arr[], int size,  int *num, int *idx) {
    *num = INF;
    for(int i = 0; i < size; i++) {
        *num = min(*num, arr[i]);
        if(*num == arr[i]) *idx = i;
    }
}

int main() {
    int size, lowerNumber, lowerIndex;
    scanf("%d", &size);
    int arr[size];
    fill(arr, size);
    lower(arr, size, &lowerNumber, &lowerIndex);
    printf("Menor valor: %d\nPosicao: %d", lowerNumber, lowerIndex);
    return 0;
}