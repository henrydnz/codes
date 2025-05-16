//https://judge.beecrowd.com/pt/problems/view/1024

#include <stdio.h>
#include <string.h> 
#include <ctype.h>

#define MAX_STR_LEN 1001

void scan_str(char *str){
    fgets(str, MAX_STR_LEN, stdin);
    strtok(str, "\n");
}

void pass1(char *str){
    while(*str){
        if(isalpha(*str))
            (*str)+=3;
        str++;
    }
}

void swap(char*a, char*b){
    char aux=*a;
    *a=*b;
    *b=aux;
}

void pass2(char *str){
    int len = strlen(str);
    char *start = str;
    char *end = str+len-1;

    while(start<end){
        swap(start, end);
        start++; 
        end--;
    }
}

void pass3(char *str){
    int len = strlen(str);
    char *half = str+len/2;
    while(*half){
        (*half)--;
        half++;
    }
}

void cripto(int str_cnt){
    while(str_cnt--){
        char str[MAX_STR_LEN];
        scan_str(str);
        pass1(str);
        pass2(str);
        pass3(str);
        printf("%s\n", str);
    }
}

int main() {
    int str_cnt;
    scanf("%d%*c", &str_cnt);
    cripto(str_cnt);
    return 0;
}