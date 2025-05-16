//https://judge.beecrowd.com/pt/problems/view/1234

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void dancing(char *str){
    for(int i=0; *str; str++){
        //ignore space
        if(*str!=' ') {
            //even : is upper, odd : is lower
            *str = i%2==0?
                (islower(*str)? toupper(*str): *str):
                (islower(*str)? *str: tolower(*str));
            i++;
        }
    }
}

int main() {
    char str[51];
    while(scanf("%[^\n]%*c", str)!=EOF){
        dancing(str);
        printf("%s\n", str);
    }

    return 0;
}