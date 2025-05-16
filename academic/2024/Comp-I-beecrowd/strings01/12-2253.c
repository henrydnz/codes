//https://judge.beecrowd.com/pt/problems/view/2253

#include <stdio.h>
#include <ctype.h>
#include <string.h> 

#define MAX 1001

int check(char *str){

    int lenght = strlen(str);
        
    if(lenght < 6 || lenght > 32)
        return 0;

    int flag_lower = 0, flag_upper = 0, flag_number = 0;

    while(*str) {
        if(islower(*str)) 
            flag_lower = 1;
        
        else if(isupper(*str))
            flag_upper = 1;

        else if(isalnum(*str)) 
            flag_number = 1;
        
        else if(ispunct(*str) || isspace(*str))
            return 0;

        str++;
    }
    
    return flag_lower && flag_upper && flag_number;
}

int main() {
    char str[MAX];

    while( scanf("%[^\n]%*c", str) != EOF ) {
        if(check(str))
            printf("Senha valida.\n");
        else 
            printf("Senha invalida.\n");
    }
    

    return 0;
}