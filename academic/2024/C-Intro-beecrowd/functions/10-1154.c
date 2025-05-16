//https://judge.beecrowd.com/pt/problems/view/1154

#include <stdio.h>

int items, sum;

int main() {
    int n=0;
    while(scanf("%d",&n)&&n>=0) {
        sum = sum + n;
        items++;
    }
    int media = (float) sum / items;
    printf("%.2f", media);
    return 0;
}  