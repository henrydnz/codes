//https://judge.beecrowd.com/pt/problems/view/1133

#include <stdio.h>

void ans(int x, int y) {
    int max, min;
    x>y? (max=x, min=y): (max=y, min=x);
    for (int i=min+1; i<max; i++) 
        if ((i%5==2)||(i%5==3)) 
            printf("%d\n", i);
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    ans(x, y);
    return 0;
}