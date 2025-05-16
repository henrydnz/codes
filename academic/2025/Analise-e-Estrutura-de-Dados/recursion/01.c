#include <stdio.h>

void ans(int n, int i) {
    if(i<=n){
        printf("%d\n", i);
        return ans(n, i+1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    ans(n, 0);
    return 0;
}