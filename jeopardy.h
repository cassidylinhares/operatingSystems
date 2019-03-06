/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern char * tokenize(char *input);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(struct player *players, int num_players);

#endif /* JEOPARDY_H_ */
