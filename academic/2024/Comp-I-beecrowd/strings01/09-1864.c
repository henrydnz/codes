//https://judge.beecrowd.com/pt/problems/view/1864

#include <stdio.h>
#include <string.h>

int main() {
    char soren[] = "LIFE IS NOT A PROBLEM TO BE SOLVED";

    int num;
    scanf("%d", &num);

    if(num > strlen(soren))
        printf("%s\n", soren);
    else {
        char *letter = soren;

        while(letter < soren+num){
            printf("%c", *letter);
            letter++;
        }

        printf("\n");
    }
    return 0;
}