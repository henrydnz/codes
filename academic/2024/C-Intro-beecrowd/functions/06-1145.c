//https://judge.beecrowd.com/pt/problems/view/1145

#include <stdio.h>

void ans(int brkNum, int max) {
    int i=1, brkLn;
    while(i<max) {
        brkLn=brkNum;
        while(brkLn--) {
            printf("%d", i++);
            if (brkLn) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    ans(x, y);
    return 0;
}