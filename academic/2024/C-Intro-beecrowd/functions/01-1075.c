//https://judge.beecrowd.com/pt/problems/view/1075

#include <stdio.h>

void ans(int x) { 
    for (int i=0;i<10000;i++) 
        if (i%x==2) 
            printf("%d\n", i); 
}

int main() {
    int x; 
    scanf("%d", &x);
    ans(x);
    return 0;
}