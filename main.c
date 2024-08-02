#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

int main(int argc, char* argv[]) {

    //if nothing is input then throw error message
    if (argc != 2) {
        printf("Please input number of champions next time\n");
        exit(-1);
    }
    int numChampions = atoi(argv[1]); // convert whatever is in the command line to int

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
        printf("\n--------- Round %d --------\n", roundNum);
        printf("\nPlayer 1's Hand: ");
        printChampionList(player1);
        printf("\nPlayer 2's Hand: ");
        printChampionList(player2);

        // send a pointer of the head so it doesnt need a return function
        fight(&player1,&player2);

        player1 = removeChampion(player1);
        player2 = removeChampion(player2);
        ++roundNum;
    }
    // determine who was the winner and print it out
    if(player1 == NULL && player2 != NULL){
        printf("\nPlayer 2 Wins!!\n");
    }
    else if (player2 == NULL && player1 != NULL){
        printf("\nPlayer 1 Wins!!\n");
    }
    else{
        printf("\nIt was a Tie!!\n");
    }


// clear the champions list and it memory
    destroyChampionList(player1);
    destroyChampionList(player2);
    return 0;
}
