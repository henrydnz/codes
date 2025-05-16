//https://judge.beecrowd.com/pt/problems/view/1364

#include <stdio.h>

void read(int array[], int size) {
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
}

int max(int x, int y) {
    return (x>y)? x: y;
}

int ans(int arr[], int n) {
    int partSize = n/3;
    int aux = 0, answer = -1e6;
    for(int i = 0; i < 3; i++) {
        for(int j = partSize*i; j < partSize*(i+1); j++)
            aux += arr[j];
        answer = max(answer, aux);
        aux = 0;
    }
    return answer;
}

int main() {
    int n; 
    scanf("%d", &n);
    int arr[n];
    read(arr, n);
    printf("%d\n", ans(arr, n));
    return 0;
}

