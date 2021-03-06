/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
char * tokenize(char *input){
    char *p = strrchr(input, ' ');
    if (p && *(p + 1)){
        return &p+1;
    }
}

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(struct player *players, int num_players){
    struct player tmp;
    for(int i=0; i < num_players; i++){
        for(int j=1; j < num_players; j++){
            if(players[j].score > players[i].score){
                tmp=players[j];
                players[i] = players[j];
                players[j] = tmp;
            }
        }
    }

    for(int i=0; i < num_players; i++){
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}

int game_state;
int numQ = NUM_QUESTIONS;

int main(){
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    struct player players[NUM_PLAYERS];

    // EXAMPLE: player 1 is named Fred
	// players[0].name = "Fred";
    strcpy(players[0].name, "Fred");
    printf("%s\n", players[0].name);

    // Buffer for user input
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    printf("%s\n", "PLEASE USE ALL CAPS WHEN RESPONDING");
    printf("%s\n", "PLEASE REPLY WITH NAME FIRST BEFORE ANSWERING A QUESTION");
    printf("%s\n", "ANSWERS MUST BEGIN WITH WHAT OR WHO");
    // Prompt for players names
    // initialize each of the players in the array
    for(int i = 0; i < NUM_PLAYERS; i++){
        printf("%s %d: ", "Enter Player", i+1);
        scanf("%[^\n]%*c", players[i].name);
        players[i].score = 0;
        printf("\n");
    }



    // Perform an infinite loop getting command input from users until game ends
    game_state = 1;
    char str[4][BUFFER_LEN] = {{0}};
    while (game_state == 1){
        char *token;
        char *name, *word;
        //display questions
        display_categories();

        //get name
        printf("%s\n", "ENTER YOUR NAME TO SELECT A CATEGORY");
        fgets(buffer, BUFFER_LEN, stdin);
        name = strtok(buffer, "\n");

        //check if player is in game
        if(player_exists(players, NUM_PLAYERS, name) == true){
            //ask player to pick category and value
            printf("%s\n", "ENTER CATEGORY VALUE");
            fgets(buffer, BUFFER_LEN, stdin);

            //rmv \n
            token = strtok(buffer, "\n");
            //get category
            word = strtok(token, " ");
            strcpy(str[0], word);
            //get val
            word = strtok(NULL, " ");
            strcpy(str[1], word);
            token = NULL;

            if(already_answered(str[0], atoi(str[1])) == true){
                printf("%s\n", "PLEASE PICK AN UNPICKED CATEGORY AND VALUE");
                //display question
                display_question(str[0], atoi(str[1]));
            }else{
                //display question
                display_question(str[0], atoi(str[1]));
            }

            memset(buffer, 0, BUFFER_LEN);
            fgets(buffer, BUFFER_LEN, stdin);

            //rmv \n
            token = strtok(buffer, "\n");

            //get beginning
            word = strtok(token, " ");
            strcpy(str[2], word);

            //get rest of answer
            word = strtok(NULL, "");
            strcpy(str[3], word);
            token = NULL;

            //1 less question to do
            numQ--;

            //validate question
            if(valid_answer(str[0], atoi(str[1]), str[3], str[2]) == true){
                printf("%s\n", "Awesome Sauce!");
                update_score(players, NUM_PLAYERS, name, atoi(str[1]));
            }else{
                printf("%s\n", "Ew!");
                display_answer(str[0], atoi(str[1]));
            }

        }else{
            printf("%s\n", "Enter an existing player name");
        }

        //check how many questions left
        if(numQ <= 0){
            game_state = 0;
        }
    }

    show_results(players, NUM_PLAYERS);

    return EXIT_SUCCESS;
}
