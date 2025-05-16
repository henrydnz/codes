//https://judge.beecrowd.com/pt/problems/view/2027

//undone

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void crypto(char *str){
    // -> 0 = 5...
    // -> 1 = 4...
    // x = 5-x, 0<=x<=5
    // ~2 = 3
    // ~3 = 2
    // char = (a -> z distance) - char
    // y1 = z - a
    // y2 = Z - A
    // char = y1 or y2 - char

    int y1 = 'z' - 'a';
    int y2 = 'A' - 'Z';
    
    while(*str){
        if(isalpha(*str))
            *str = (islower(*str)? y1: y2) - *str;    
        else if(isalnum(*str))
            *str = '!' + (*str + '0');    //char + '0' = char to reciprocal int
        else if(isspace(*str))
            *str = '\\';
        str++;
    }
}

int main() {
    char str[1001];
    
    scanf("%[^#]", str);
    crypto(str);
    return 0;
}
