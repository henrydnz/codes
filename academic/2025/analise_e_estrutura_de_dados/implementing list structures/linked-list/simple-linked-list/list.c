#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *newList(){
    List *new = (List*) malloc(sizeof(List));
    new->next = NULL;
    return new;
}

int isEmpty(List *l){
    return l->next==NULL;
}

void insertItem(List *l, dataType x){
    

}