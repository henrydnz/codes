//https://judge.beecrowd.com/pt/problems/view/1258

#include <stdio.h>
#include <string.h>
#define MAX_NM_LEN 50
#define MAX_SHIRT_CNT 60

typedef struct {
    char name[MAX_NM_LEN];
    char color[9];
    char size;
} Shirt;       

void swap(Shirt *s1, Shirt *s2){
    Shirt aux = *s1;
    *s1 = *s2;
    *s2 = aux;
}

void read_shirts(Shirt *shirts, int count){
    for(int i=0;i<count;i++){
        scanf("%[^\n]%*c", shirts[i].name);
        scanf("%[^' ']%*c", shirts[i].color);
        scanf("%c%*c", &shirts[i].size);
    }

}

void organize_shirts(Shirt *shirts, int count){
    for(int i=0;i<count-1;i++)
        for(int j=i+1;j<count;j++){
            if(strcmp(shirts[i].color,shirts[j].color)>0)
                swap(&shirts[i],&shirts[j]);
            else if(strcmp(shirts[i].color,shirts[j].color)==0)
                if(shirts[i].size < shirts[j].size)
                    swap(&shirts[i],&shirts[j]);
                else if(shirts[i].size == shirts[j].size)
                    if(strcmp(shirts[i].name,shirts[j].name)>0)
                        swap(&shirts[i],&shirts[j]);

        }
}

void show_shirts(Shirt *shirts, int count){
    for(int i=0; i<count; i++){
        printf("%s %c %s\n", shirts[i].color, shirts[i].size, shirts[i].name);
    }
}

int main() {
    Shirt shirts[MAX_SHIRT_CNT];
    int count;
    scanf("%d%*c", &count);

    while(count){
        read_shirts(shirts, count);
        organize_shirts(shirts, count);
        show_shirts(shirts, count);

        scanf("%d%*c", &count);
        if(count)
            printf("\n");
    }
    return 0;
}