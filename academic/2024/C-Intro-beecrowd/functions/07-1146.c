//https://judge.beecrowd.com/pt/problems/view/1146

#include <stdio.h>

int x;
void ans() {
    while(scanf("%d", &x)&&x) {
        for(int i=1;i<=x;i++) {
            printf("%d", i);
            if (!(i==x)) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    ans();
    return 0;
}