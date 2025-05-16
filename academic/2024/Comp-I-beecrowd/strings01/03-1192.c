//https://judge.beecrowd.com/pt/problems/view/1192

#include <stdio.h>


int compute(int x, char c, int y){
    if(x==y)       
        return x*y;

    if(c>='a')     
        return x+y;

        return y-x;   
}

int main() {
    int tests;
    scanf("%d%*c", &tests);
    for(int i = 0; i < tests; i++) {
        int x, y;
        char c;
        scanf("%d", &x);
        scanf("%c", &c);
        scanf("%d%*c", &y);
        printf("%d\n", compute(x,c,y));
    }
    return 0;
}