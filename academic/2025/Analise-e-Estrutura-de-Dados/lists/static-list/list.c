#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List *newList(){
    List *new = (List*) malloc(sizeof(List));
    new->free_pos = 0;
    return new;
}

int isEmpty(List *l){
    return l->free_pos == 0;
}

void insertItem(List *l, dataType x){
    if(l->free_pos>=MAX_SZ)
        printf("The list is full!");
    else
        l->info[l->free_pos++] = x;
}

void deleteItem(List *l, dataType x){
    if(isEmpty(l))
        printf("The list is empty!");
    else{
        int position = 0;
        while(position < l->free_pos && x != l->info[position])
            position++;
        if(position == l->free_pos)
            printf("item was not found.");
        else{
            for(int i=position; i<l->free_pos; i++)
                l->info[i] = l->info[i+1];
            l->free_pos--;
        }
    }
}

void showList(List *l){
    printf("[");
    for(int i=0; i<l->free_pos; i++){
        printf("%d", l->info[i]);
        if(i<l->free_pos-1)
            printf(", ");
    }
    printf("]\n");
}

