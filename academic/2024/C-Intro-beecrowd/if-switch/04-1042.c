//https://judge.beecrowd.com/pt/problems/view/1042

#include <stdio.h>


int main() {
    
    int a, b, c, x, y, z;

    scanf("%d%d%d", &a, &b, &c);

    if ((a<b) && (b<c)) { x=a; y=b; z=c;}           // a b c
    else if ((a<c) && (c<b)) { x=a; y=c; z=b; }     // a c b
    else if ((b<a) && (a<c)) { x=b; y=a; z=c; }     // b a c
    else if ((b<c) && (c<a)) { x=b; y=c; z=a; }     // b c a
    else if ((c<a) && (a<b)) { x=c; y=a; z=b; }     // c a b
    else if ((c<b) && (b<a)) { x=c; y=b; z=a; }     // c b a  

    printf("%d\n%d\n%d\n \n %d\n%d\n%d\n", x, y, z, a, b, c);

    return 0;
}