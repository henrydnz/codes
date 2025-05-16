#ifndef LIST_H
#define LIST_H

#define MAX_SZ 1000

typedef int dataType;

typedef struct {
    dataType info[MAX_SZ];
    int free_pos;
} List;

List* newList();

int isEmpty(List *l);

void insertItem(List *l, dataType x);

void deleteItem(List *l, dataType x);

void showList(List *l);

#endif

