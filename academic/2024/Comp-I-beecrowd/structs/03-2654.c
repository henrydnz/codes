//https://judge.beecrowd.com/pt/problems/view/2654

#include <stdio.h>
#include <string.h>
#define MAX_N 100
#define MAX_H 100
#define MAX_D 100

typedef struct {
    char name[MAX_N];
    int power;
    int kills;
    int deaths;
} Hero;

void scan_hero(Hero *hero){
    scanf("%[^' ']%*c", hero->name);
    scanf("%d%*c%d%*c%d%*c", &hero->power, &hero->kills, &hero->deaths);
}

void swap_hero(Hero *a, Hero *b){
    Hero c = *a; *a = *b; *b = c;
}

void battle(Hero heroes[], Hero *winner, int size){
    //bubble sort for all, winner is the first HEHEHEHEHEHEHHEHEHEH efficiency
    for(int i=0; i<size-1; i++)
        for(int j=i+1; j<size; j++)
            if(
                (heroes[i].power<heroes[j].power) ||
                (heroes[i].power==heroes[j].power && heroes[i].kills<heroes[j].kills) ||
                (heroes[i].power==heroes[j].power && heroes[i].kills==heroes[j].kills && 
                    heroes[i].deaths>heroes[j].deaths) ||
                (heroes[i].power==heroes[j].power && heroes[i].kills==heroes[j].kills &&
                    heroes[i].deaths==heroes[j].deaths && strcmp(heroes[i].name, heroes[j].name)>0)
            )
                swap_hero(&heroes[i], &heroes[j]);
    *winner = heroes[0];
}

int main(){
    Hero heroes[MAX_H], winner;
    int size;

    scanf("%d%*c", &size);

    for(int i=0;i<size;i++)
        scan_hero(&heroes[i]);

    battle(heroes, &winner, size);
    printf("%s\n", winner.name);

    return 0;
}