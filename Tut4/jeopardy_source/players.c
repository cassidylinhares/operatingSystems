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
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(struct player *players, int num_players, char *name){
    bool exist;
    for (int i = 0; i<num_players; i++) {
        if (strcmp(name, players[i].name)==0) {
            exist = true;
            break;
        }else {
            exist = false;
        }

    }
    return exist;
}

// Go through the list of players and update the score for the
// player given their name
void update_score(struct player *players, int num_players, char *name, int score){
    for (int i = 0; i<num_players; i++) {
        if (strcmp(name, players[i].name)==0) {
            players[i].score += score;
        }
    }
}
