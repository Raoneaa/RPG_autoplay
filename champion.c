#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("%c%d ",head->role,head->level);
    printChampionList(head->next);
}

// Remove the head of the linked list and return the new head
Champion* removeChampion(Champion *head) {
    if (head == NULL || head ->next == NULL) {
        return NULL;
    }

    Champion* newHead = head->next;
    free(head);
    return newHead;
}

// Remove all the champions from the linked list and return null
Champion* destroyChampionList(Champion *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Champion *next = head->next;
    free(head);
    head = NULL;
    return destroyChampionList(next);
}

void fight(Champion** player1List, Champion** player2List) {
    // make structs equal to the lists
    Champion *player1 = *player1List;
    Champion *player2 = *player2List;
    char player1Role[10] = "BlankSpace";
    char player2Role[10] = "BlankSpace";
    switch (player1->role) {
        case MAGE:
            strcpy(player1Role,"MAGE");
            break;
        case FIGHTER:
            strcpy(player1Role,"FIGHTER");
            break;
        case SUPPORT:
            strcpy(player1Role,"SUPPORT");
            break;
        case TANK:
            strcpy(player1Role,"TANK");
            break;

    }
    switch (player2->role) {
        case MAGE:
            strcpy(player2Role,"MAGE");
            break;
        case FIGHTER:
            strcpy(player2Role,"FIGHTER");
            break;
        case SUPPORT:
            strcpy(player2Role,"SUPPORT");
            break;
        case TANK:
            strcpy(player2Role,"TANK");
            break;

    }
// if both have the same roles
    if (player1->role == player2->role) {
        switch (player1->role) {
            case MAGE:
                // higher level wins and gains champion, if tie nothing
                if (player1->level > player2->level) {
                    addChampion(player1, createChampion());
                    printf("Player %d is %s and gains new champion",player1->level,player1Role);
                } else if (player1->level < player2->level) {
                    addChampion(player2, createChampion());
                    printf("Player %d is a %s and gains new champion",player2->level,player2Role);
                }
                break;
            case FIGHTER:
                // both win a champion no matter what
                addChampion(player1, createChampion());
                printf("Player %d is a %s and gains new champion",player1->level,player1Role);
                addChampion(player2, createChampion());
                printf("Player %d is a %s and gains new champion",player2->level,player2Role);
                break;
            case SUPPORT:
                //both loose one champion
                removeChampion(player1);
                removeChampion(player2);
                break;
            case TANK:
                // nothing happens
                break;
        }
    }
        //if player 1 has a higher level
    else if (player1->level > player2->level) {
        //determine the outcome on each of the player 1 champion role
        switch (player1->role) {
            case MAGE:
                // check for what role the losing player was to determine fate
                switch (player2->role) {
                    //player 2 looses as mage
                    case MAGE:
                        //remove champion for loosing
                        removeChampion(player2);
                        break;
                    case FIGHTER:
                        //loose with no penalty
                        break;
                    case SUPPORT:
                    case TANK:
                        //remove for loosing as support or tank
                        removeChampion(player2);
                        break;
                }
                //mage wins gains new champion
                addChampion(player1, createChampion());

                break;
            case FIGHTER:
                if (player2->role == SUPPORT) {
                    //remove for loosing as support
                    removeChampion(player2);
                }
                //just loose normal if player 2 is tank
                // nothing happens
                break;
            case SUPPORT:
                if (player2->role == TANK) {
                    //player 2 wins for being tank
                    addChampion(player1, createChampion());
                    printf("Player %d is a %s and gains new champion",player1->level,player1Role);

                    addChampion(player2,createChampion());
                    printf("Player %d is a %s and gains new champion",player2->level,player2Role);
                }
                //Nothing happens
                break;
            case TANK:
                if(player2->role == MAGE){
                    addChampion(player2,createChampion());
                    printf("Player %d is a %s and gains new champion",player2->level,player2Role);
                }
                if(player2->role == SUPPORT){
                    addChampion(player1,createChampion());
                    printf("Player %d is a %s and gains new champion",player1->level,player1Role);
                }
                // nothing happens
                break;
        }
    }
    // if player 2 wins
    else if (player2->level > player1->level) {
        //determine the outcome on each of the player 1 champion role
        switch (player1->role) {
            case MAGE:
                // check for what role the losing player was to determine fate
                switch (player2->role) {
                    //player 2 looses as mage
                    case MAGE:
                        //remove champion for loosing
                        removeChampion(player1);
                        break;
                    case FIGHTER:
                        //loose with no penalty
                        break;
                    case SUPPORT:
                    case TANK:
                        //remove for loosing as support or tank
                        removeChampion(player1);
                        break;
                }
                //mage wins gains new champion
                addChampion(player2, createChampion());
                printf("Player %d is a %s and gains new champion",player2->level,player2Role);

                break;
            case FIGHTER:
                if (player2->role == SUPPORT) {
                    //remove for loosing as support
                    removeChampion(player1);
                    // add to player 2 for winning as support
                    addChampion(player2,createChampion());
                    printf("Player %d is a %s and gains new champion",player2->level,player2Role);
                }
                //just loose normal if player 2 is tank
                // nothing happens
                break;
            case SUPPORT:
                if (player2->role == TANK) {
                    //player 2 wins for being tank
                    addChampion(player1, createChampion());
                    printf("Player %d is a %s and gains new champion",player1->level,player1Role);
                }
                //Nothing happens
                break;
            case TANK:
                if(player2->role == MAGE){
                    addChampion(player2,createChampion());
                    printf("Player %d is a %s and gains new champion",player2->level,player2Role);
                }
                if(player2->role == SUPPORT){
                    addChampion(player1,createChampion());
                    printf("Player %d is a %s and gains new champion",player1->level,player1Role);
                }

                break;
        }
    }
}
