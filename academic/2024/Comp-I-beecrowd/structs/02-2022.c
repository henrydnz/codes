//https://judge.beecrowd.com/pt/problems/view/2022

#include <stdio.h>
#include <string.h>
#define MAX_N 20
#define MAX_G 100

typedef struct {
    char name[MAX_N];
    float price;
    int pref;
} Gift;

typedef struct {
    char name[MAX_N];
    int gift_count;
    Gift gifts[MAX_G];    
} Kid;

void read_gift(Gift *gift){
    scanf("%[^\n]%*c", gift->name);
    scanf("%f%*c%d%*c", &gift->price, &gift->pref);
}

void swap(Gift *a, Gift *b){
    Gift aux = *a;
    *a = *b;
    *b = aux;
}

void organize_gifts(Gift gifts[], int gift_count){
    for(int i=0;i<gift_count-1;i++)
        for(int j=i+1;j<gift_count;j++)
            if(gifts[i].pref < gifts[j].pref)
                swap(&gifts[i],&gifts[j]);
            else if(gifts[i].pref == gifts[j].pref)
                if(gifts[i].price > gifts[j].price)
                    swap(&gifts[i],&gifts[j]);
                else if(gifts[i].price == gifts[j].price)
                    if(strcmp(gifts[i].name,gifts[j].name)>0)
                        swap(&gifts[i],&gifts[j]);
}

void show_list(Kid kid){
    printf("Lista de %s", kid.name);
    for(int i=0;i<kid.gift_count;i++){
        printf("%s - R$%.2f\n", kid.gifts[i].name, kid.gifts[i].price);
    }
    printf("\n");
}

int main(){

    Kid kid;

    while(scanf("%[^' ']%*c", kid.name)!=EOF){
        scanf("%d%*c", &kid.gift_count);

        for(int i=0;i<kid.gift_count;i++)
            read_gift(&kid.gifts[i]);

        organize_gifts(kid.gifts, kid.gift_count);

        show_list(kid);
    }

    return 0;
}