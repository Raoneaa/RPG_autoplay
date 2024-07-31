//
// Created by Julian on 7/23/2024.
//

#ifndef PROJECT3_CHAMPION_H
#define PROJECT3_CHAMPION_H
typedef enum {M,F,S,T}ChampionRole;

typedef struct Champion{
    char role;
    int level;
    struct Champion* next;
}Champion;


Champion* createChampion(); // create the linked list dynamically

Champion* addChampion(Champion *head, Champion *c); //add new champion struct object to the linked list,
// c is the struct object
Champion* buildChampionList(int n); //creates a lis tof champions with linked list, use createChampion() and addChampion();
void printChampionList(Champion *head); // traverse linked list for each player than print it out
Champion* removeChampion(Champion *head); // removed the head of the linked list then returns new head
Champion* destroyChampionList(Champion *head); // remove all the champions from linked list and returns null



#endif //PROJECT3_CHAMPION_H
