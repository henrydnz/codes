//https://judge.beecrowd.com/pt/problems/view/1172

#include <stdio.h>

int main() {
    int X[10];
    for(int i = 0; i < 10; i++) {
        int insert;
        scanf("%d\n", &insert);
        X[i] = (insert > 0)? insert: 1;
    }
    for(int i = 0; i < 10; i++)
        printf("X[%d] = %d\n", i, X[i]);
    return 0;
}