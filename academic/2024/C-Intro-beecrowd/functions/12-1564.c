//https://judge.beecrowd.com/pt/problems/view/1564

#include <stdio.h>

int main() {
    int x;
    while(scanf("%d", &x)!=EOF) 
        printf(x? "vai ter duas!\n": "vai ter copa!\n");
    return 0;
}