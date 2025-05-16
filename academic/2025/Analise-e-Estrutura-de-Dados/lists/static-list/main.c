#include "list.h"
#include <stdio.h>

int main(){
    List *l;
    l = newList();
    printf("input 10 integers to insert in the list.\n");
    int i=10;
    while(i--){
        int x;
        scanf("%d", &x);
        insertItem(l, x);
    }
    printf("Here's your list: ");
    showList(l);
    printf("input 3 items to delete from the list:\n");
    i=3;
    while(i--){
        int x;
        scanf("%d", &x);
        deleteItem(l, x);
    }
    printf("The final list is: ");
    showList(l);
}