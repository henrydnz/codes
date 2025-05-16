//https://judge.beecrowd.com/pt/problems/view/1235

#include <stdio.h>
#include <string.h>

void split(char *src, char *dst1, char *dst2) {
    int src_half_len = strlen(src) / 2;
    //half pointer to stop loop
    char *ptr_half_len = src + src_half_len;    
    //dst1 -> 1st half, dst2 -> 2nd half
    while (src < ptr_half_len) {
        *dst1 = *src;
        *dst2 = *(src + src_half_len);
        dst1++;
        dst2++;
        src++;
    }
    *dst1 = '\0';
    *dst2 = '\0';
}

void invert(char *src) {
    int src_len = strlen(src);
    char *start = src;
    char *end = src + src_len - 1;

    while (start < end) {
        char aux = *start;
        *start = *end;
        *end = aux;
        start++;
        end--;
    }
}

void virus(char *str) {
    char str1[51], str2[51];
    split(str, str1, str2);     //divide main string in two substrings
    invert(str1);               //invert each substring
    invert(str2);
    strcpy(str, strcat(str1, str2));    //concatenate substrings
                                        //copy to main string
}

int main() {    
    int tests;
    scanf("%d%*c", &tests);
    while (tests--) {
        char str[101];
        scanf("%[^\n]%*c", str);
        virus(str); 
        printf("%s\n", str);
    }    
    return 0;
}