#include <stdio.h>

int ans(int n, int acc){
    if(n==0)
        printf("d", acc);
    return ans(n-1, n+acc);
}

int main() {
    int n;
    scanf("%d", &n);
    return 0;
}