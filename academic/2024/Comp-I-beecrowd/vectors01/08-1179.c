#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void show(int array[], int size, int parity) {
    for(int i = 0; i < size; i++) {
        printf(parity? "impar": "par");
        printf("[%d] = %d\n", i, array[i]);
    }
}

int main() {
    int array[2][MAX], count[2] = {0, 0}, quotes = 15, q, parity;
    while(quotes--) {
        scanf("%d", &q);
        parity = abs(q%2);
        array[parity][count[parity]] = q;
        count[parity]++;
        if(count[parity] == MAX) {
            count[parity] = 0;
            show(array[parity], MAX, parity);
        }
    }
    show(array[1], count[1], 1);
    show(array[0], count[0], 0);
    return 0;
}


