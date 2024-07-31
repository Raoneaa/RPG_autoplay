#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"

int main(int argc, char* argv[]) {

    // if nothing is input then throw error message
//    if(argc != 2){
//        printf("Please input number of champions next time\n");
//        exit(-1);
//    }
//    int numChampions = atoi(argv[1]); // convert whatever is in the command line to int
    int numChampions = 4;

    if( numChampions <= 0){
        printf("You cannot play a game with 0 champions, input more than 0 champions next time\n");
    }

    srand(time(NULL)); // seed randomizer with the time for a little better randomization

// build champion list for player1 1, if not make throw error code then end program
    Champion* player1 = buildChampionList(numChampions);
    if(player1 == NULL){
        printf("error building player1's list\n");
        exit(-1);
    }
// build champion lis for player1 2, if not allocated properly throw error code and end program
    Champion* player2 = buildChampionList(numChampions);
    if(player2 == NULL){
        printf("error building opponents list");
        exit(-2);
    }
    int roundNum = 1;
        // initialize round num
        // print current game info
        printf("--------- Round %d ---------\n",roundNum);
        printf("Player 1's Champions: ");
        printChampionList(player1);
        printf("\nPlayer 2's Champions: ");
        printChampionList(player2);
    removeChampion(player2);
    removeChampion(player1);


    printf("after removing head\n");

    printChampionList(player1);
    printChampionList(player2);
    destroyChampionList(player1);
    destroyChampionList(player2);

    printf("after freeing\n");
    printChampionList(player1);
    printChampionList(player2);

    return 0;
}
