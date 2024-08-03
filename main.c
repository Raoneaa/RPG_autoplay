#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "champion.h"

int main(int argc, char* argv[]) {
    char player1Role[10] = "BlankSpace";
    char player2Role[10] = "BlankSpace";

    // //if nothing is input then throw error message
    // if (argc != 2) {
    //     printf("Please input number of champions next time\n");
    //     exit(-1);
    // }
    // int numChampions = atoi(argv[1]); // convert whatever is in the command line to int
    int numChampions = 4;

    if (numChampions <= 0) {
        printf("You cannot play a game with 0 champions, input more than 0 champions next time\n");
    }

    srand(time(NULL)); // seed randomizer with the time for a little better randomization

// build champion list for player1 1, if not make throw error code then end program
    Champion *player1 = buildChampionList(numChampions);
    if (player1 == NULL) {
        printf("error building player1's list\n");
        exit(-1);
    }
// build champion lis for player1 2, if not allocated properly throw error code and end program
    Champion *player2 = buildChampionList(numChampions);
    if (player2 == NULL) {
        printf("error building opponents list");
        exit(-2);
    }
    int roundNum = 1;
    while (player1 != NULL && player2 != NULL) {
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
        printf("\n--------- Round %d --------\n", roundNum);
        printf("\nPlayer 1's Hand: ");
        printChampionList(player1);
        printf("\nPlayer 2's Hand: ");
        printChampionList(player2);
        printf("\nPlayer 1 is a %s and Player 2 is a %s\n",player1Role,player2Role);

        // send a pointer of the head so it doesnt need a return function
        fight(&player1,&player2);

        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        ++roundNum;
    }
    // determine who was the winner and print it out
    printf("\n---------- Game Over!! ---------\n");
    if(player1 == NULL && player2 != NULL){
        printf("\nPlayer 1 ending champion list: ");
        printf("\nPlayer 2 ending champion list: ");
        printChampionList(player2);
        printf("\nPlayer 2 Wins!!\n");
    }
    else if (player2 == NULL && player1 != NULL){
        printf("\nPlayer 1 ending champion list: ");
        printChampionList(player1);
        printf("\nPlayer 2 ending champion list: ");
        printf("\nPlayer 1 Wins!!\n");
    }
    else{
        printf("\nPlayer 1 ending champion list: ");
        printf("\nPlayer 2 ending champion list: ");
        printf("\nIt was a Tie!!\n");
    }

    printChampionList(player1);
    printChampionList(player2);


// clear the champions list and it memory
    destroyChampionList(player1);
    destroyChampionList(player2);
    return 0;
}
