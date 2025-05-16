//https://judge.beecrowd.com/pt/problems/view/3551

#include <stdio.h>

void read(int v[], int size) {
    for(int i = 0; i < size; i++) 
        scanf("%d", &v[i]);
}

int check(int v[], int size) {
    int parity[2];
    parity[0] = v[0]%2;
    parity[1] = v[1]%2;

    for(int i = 2; i < size; i++)
        if(i%2) {
            if(v[i]%2 != parity[1])
                return 0;
        } else {
            if(v[i]%2 != parity[0])
                return 0;
        }
    return 1;
}

void test() {
    int size; 
    scanf("%d", &size);
    int v[size];
    read(v, size);
    printf(check(v, size)? "YES\n" : "NO\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) test();

    return 0;
}