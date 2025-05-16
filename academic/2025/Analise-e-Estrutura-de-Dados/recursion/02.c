#include <stdio.h>

void ans(int n){
    if(n>=0) {
        printf("%d\n", n);
        return ans(n-1);
    }   
}

int main() {
    int n;
    scanf("%d", &n);
    ans(n);
    return 0;
}