#include <stdio.h>
#include <stdlib.h>
#include "champion.h"

// Create the linked list dynamically
Champion* createChampion() {
    Champion *champ = (Champion *)malloc(sizeof(Champion));
        if (champ == NULL) {
            printf("Error building champion list\n");
            return NULL;
        }

        int role = rand() % 4;
        switch (role) {
            case 0:
                champ->role = MAGE; // Ensure consistency with char type
                break;
            case 1:
                champ->role = FIGHTER;
                break;
            case 2:
                champ->role = SUPPORT;
                break;
            case 3:
                champ->role = TANK;
                break;
            default:
                printf("Random number generation error, iteration\n");
                break;
        }

        // Assign level based on role
        switch (champ->role) {
            case 'M':
                champ->level = rand() % 3 + 5;
                break;
            case 'F':
                champ->level = rand() % 4 + 1;
                break;
            case 'S':
                champ->level = rand() % 3 + 3;
                break;
            case 'T':
                champ->level = rand() % 8 + 1;
                break;
            default:
                break;
    }
    return champ;
}

// Add a new champion to the linked list in a sorted manner based on level
Champion* addChampion(Champion* head, Champion* c) {
    // Base case: If the head is NULL or the new champion should be inserted before the head
    if (head == NULL || head->level < c->level) {
        c->next = head;
        return c;
    }
    // Recursive case: Proceed to the next node
    head->next = addChampion(head->next, c);
    return head;
}

// Build a list of champions by calling createchampion however many times the champions are then returns the head for it;
Champion* buildChampionList(int n) {
    Champion * head = NULL;
    for(int i = 0; i < n;++i){
        Champion* champ = createChampion();
        head = addChampion(head,champ);
    }
    return head;
}

void printChampionList(Champion * head) {
    if(head == NULL) {
        return;
    }
    printf("%c%d\t",head->role,head->level);
    printChampionList(head->next);
}

// Remove the head of the linked list and return the new head
Champion* removeChampion(Champion *head) {
    if (head == NULL) {
        return NULL;
    }

    Champion* newHead = head->next;
    free(head);
    return newHead;
}

// Remove all the champions from the linked list and return null
Champion* destroyChampionList(Champion *head) {
    if (head == NULL) {
        return NULL;
    }
    Champion *next = head->next;
    free(head);
    head = NULL;
    return destroyChampionList(next);
}

void fight(Champion** player1List, Champion** player2List){
    // make structs equal to the lists
    Champion *player1= *player1List;
    Champion *player2 = *player2List;

     if(player1->level > player2->level){

     }
}
