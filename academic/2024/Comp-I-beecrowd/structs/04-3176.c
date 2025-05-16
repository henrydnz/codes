//https://judge.beecrowd.com/pt/problems/view/3176

#include <stdio.h>
#include <string.h>
#define MAX_N 21
#define MAX_E 30
#define MAX_T MAX_E/3

typedef struct {
    char name[MAX_N];
    int age;
} Elf;

typedef struct {
    Elf leader;
    Elf delivery;
    Elf pilot;
} Team;

void swap_elf(Elf *a, Elf *b){
    Elf c = *a; *a = *b; *b = c;
}

void scan_elf(Elf *elf) {
    scanf("%[^' ']%*c%d%*c", elf->name, &elf->age);
}

void order_elves(Elf elves[], int count) {\
    //bubble sort
    for(int i=0; i<count-1; i++)
        for(int j=i+1; j<count; j++)
            if(
                (elves[i].age<elves[j].age) ||
                (elves[i].age==elves[j].age && strcmp(elves[i].name, elves[j].name)>0)
            )
                swap_elf(&elves[i], &elves[j]);
}

void make_teams(Team teams[], Elf elves[], int team_count){
    for(int i=0; i<team_count; i++) {
        teams[i].leader = elves[i];
        teams[i].delivery = elves[i + team_count];
        teams[i].pilot = elves[i + 2*team_count];
    }
}

void show_teams(Team teams[], int count){
    for(int i=0; i<count; i++){
        printf("Time %d\n", i+1); 
        printf("%s %d\n", teams[i].leader.name, teams[i].leader.age);
        printf("%s %d\n", teams[i].delivery.name, teams[i].delivery.age);
        printf("%s %d\n", teams[i].pilot.name, teams[i].pilot.age);
        printf("\n");
    }
}

int main(){
    Elf elves[MAX_E];
    Team teams[MAX_T];
    int elf_count, team_count;

    scanf("%d%*c", &elf_count);
    team_count = elf_count/3;

    for(int i=0; i<elf_count; i++)
        scan_elf(&elves[i]);
    
    order_elves(elves, elf_count);
    make_teams(teams, elves, team_count);
    show_teams(teams, team_count);

    return 0;
}