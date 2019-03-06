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
#include "questions.h"


// Initializes the array of questions for the game
void initialize_game(void){
    // initialize each question struct and assign it to the questions array
    questions[0] = {categories[0], "A ball of gas", "WHAT", "STAR", 200, false};
    questions[1] = {categories[0], "Only planet to have life", "WHAT", "EARTH", 400, false};
    questions[2] = {categories[0], "A mini planet that orbits a planet", "WHAT", "MOON", 600, false};
    questions[3] = {categories[0], "Rotating clockwise it is the slowest rotating planet", "WHAT", "VENUS", 800, false};
    questions[4] = {categories[1], "Adventure Theme Park in California is known as ___", "WHAT", "DISNEYLAND", 200, false};
    questions[5] = {categories[1], "Born in 1901 he is the creator of Disney World but went by ___", "WHO", "WALT", 400, false};
    questions[6] = {categories[1], "A Princess named after always being in covered in soot", "WHO", "CINDERELLA", 600, false};
    questions[7] = {categories[1], "Disney Studio's 1st animated character", "WH0", "OSWALD", 800, false};
    questions[8] = {categories[2], "sqrt(64)", "WHAT", "8", 200, false};
    questions[9] = {categories[2], "Roots provide plant with nutrients and act as a(n) __", "WHAT", "ANCHOR", 400, false};
    questions[10] = {categories[2], "Benign: gentle/harmless; Benefit: profit/pros", "WHAT", "BENE", 600, false};
    questions[11] = {categories[2], "This tree has a root node which is the parent; it can branch to at most 2 children", "WHAT", "BINARY", 800, false};
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(){
    for(int i = 0; i < NUM_CATEGORIES; i++){
        printf("%s        \n", categories[i]);
        for(int j=i;j<NUM_QUESTIONS;j+=4){
            printf("$%d        \n", questions[j].value);
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value){
    for(int i=0; i <NUM_CATEGORIES;i++){
        if(strcmp(questions[i].category, category) == 0  && questions[i].value == value){
            printf("%s\n", questions[i].question);
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer, char * start){
    bool correct = false;

    for(int i=0; i <NUM_CATEGORIES;i++){
        if(strcmp(questions[i].category, category) == 0  && questions[i].value == value){
            if(strcmp(questions[i].begin, start) == 0 && strcmp(questions[i].answer, answer) == 0 ){
                bool = correct;
                break;
            }
        }
    }
    return correct;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value){
    // lookup the question and see if it's already been marked as answered
    bool answered = false;

    for(int i=0; i <NUM_CATEGORIES;i++){
        if(strcmp(questions[i].category, category) == 0  && questions[i].value == value){
            if(question[i].answered == true){
                answered = true;
                break;
            }
        }
    }
    return answered;
}
