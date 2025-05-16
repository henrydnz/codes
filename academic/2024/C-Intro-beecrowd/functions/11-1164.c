//https://judge.beecrowd.com/pt/problems/view/1164

#include <stdio.h>
void ans() {
    int x, sum=0; 
    scanf("%d", &x);
    printf("%d ", x);
    for(int i=1;i<x;i++) 
        if(!(x%i)) 
            sum+=i;
    if(sum!=x) 
        printf("nao ");
    printf("eh perfeito\n");
}

int main() {
    int x; 
    scanf("%d", &x);
    while(x--) 
        ans();
    return 0;
}
