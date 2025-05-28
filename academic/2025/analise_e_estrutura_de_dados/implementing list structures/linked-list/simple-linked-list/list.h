#ifndef LIST_H
#define LIST_H

typedef int dataType;

typedef struct node{
    dataType data;
    struct node* next;
} List;

List* newList();

int isEmpty(List *l);

void insertItem(List *l, dataType x);

void deleteItem(List *l, dataType x);

void showList(List *l);

#endif