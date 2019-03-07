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
    strcpy(questions[0].category, "SPACE");
    strcpy(questions[0].question, "A ball of gas");
    strcpy(questions[0].begin , "WHAT");
    strcpy(questions[0].answer, "STAR");
    questions[0].value = 200;
    questions[0].answered = false;

    strcpy(questions[1].category, "SPACE");
    strcpy(questions[1].question, "Only planet with known life");
    strcpy(questions[1].begin , "WHAT");
    strcpy(questions[1].answer, "EARTH");
    questions[1].value = 400;
    questions[1].answered = false;

    strcpy(questions[2].category, "SPACE");
    strcpy(questions[2].question, "A mini planet that orbits a planet");
    strcpy(questions[2].begin , "WHAT");
    strcpy(questions[2].answer, "MOON");
    questions[2].value = 600;
    questions[2].answered = false;

    strcpy(questions[3].category, "SPACE");
    strcpy(questions[3].question, "Rotating clockwise it is the slowest rotating planet");
    strcpy(questions[3].begin , "WHAT");
    strcpy(questions[3].answer, "VENUS");
    questions[3].value = 800;
    questions[3].answered = false;

    strcpy(questions[4].category, "DISNEY");
    strcpy(questions[4].question, "Adventure Theme Park in California is known as ___");
    strcpy(questions[4].begin , "WHAT");
    strcpy(questions[4].answer, "DISNEYLAND");
    questions[4].value = 200;
    questions[4].answered = false;

    strcpy(questions[5].category, "DISNEY");
    strcpy(questions[5].question, "Born in 1901 he is the creator of Disney World but went by ___");
    strcpy(questions[5].begin , "WHO");
    strcpy(questions[5].answer, "WALT");
    questions[5].value = 400;
    questions[5].answered = false;

    strcpy(questions[6].category, "DISNEY");
    strcpy(questions[6].question, "A Princess named after always being in covered in soot");
    strcpy(questions[6].begin , "WH0");
    strcpy(questions[6].answer, "CINDERELLA");
    questions[6].value = 600;
    questions[6].answered = false;

    strcpy(questions[7].category, "DISNEY");
    strcpy(questions[7].question, "Disney Studio's 1st animated character");
    strcpy(questions[7].begin , "WH0");
    strcpy(questions[7].answer, "OSWALD");
    questions[7].value = 800;
    questions[7].answered = false;

    strcpy(questions[8].category, "ROOTS");
    strcpy(questions[8].question, "sqrt(64)");
    strcpy(questions[8].begin , "WHAT");
    strcpy(questions[8].answer, "8");
    questions[8].value = 200;
    questions[8].answered = false;

    strcpy(questions[9].category, "ROOTS");
    strcpy(questions[9].question, "Roots provide plant with nutrients and act as a(n) __");
    strcpy(questions[9].begin , "WHAT");
    strcpy(questions[9].answer, "ANCHOR");
    questions[9].value = 400;
    questions[9].answered = false;

    strcpy(questions[10].category, "ROOTS");
    strcpy(questions[10].question, "Benign: gentle/harmless; Benefit: profit/pros");
    strcpy(questions[10].begin , "WHAT");
    strcpy(questions[10].answer, "BENE");
    questions[10].value = 600;
    questions[10].answered = false;

    strcpy(questions[11].category, "ROOTS");
    strcpy(questions[11].question, "This tree has a root node which is the parent; it can branch to at most 2 children");
    strcpy(questions[11].begin, "WHAT");
    strcpy(questions[11].answer, "BINARY");
    questions[11].value = 800;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(){
    for(int i = 0; i < NUM_CATEGORIES; i++){
        printf("%s        ", categories[i]);
    }
    printf("\n");
    for(int i=0;i<4;i++){
        for(int j = i; j <NUM_QUESTIONS; j+=4){
            if(questions[j].answered == true){
                printf("%s           ", "XXX");
            }else{
                printf("%d           ", questions[j].value);
            }
        }
        printf("\n");
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value){
    for(int i= 0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0  && questions[i].value == value){
            printf("%s\n", questions[i].question);
        }
        //printf("1: %s 2: %s\n", questions[i].category, category);
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer, char * start){
    bool correct = false;
    for(int i=0; i <NUM_QUESTIONS;i++){
        if(strcmp(questions[i].category, category) == 0  && questions[i].value == value){
            if(strcmp(questions[i].begin, start) == 0 && strcmp(strstr(answer, questions[i].answer), questions[i].answer) == 0 ){
                correct = true;
                break;
            }
            questions[i].answered = true;
        }
    }

    return correct;
}

void display_answer(char *category, int value){
    for(int i=0; i <NUM_QUESTIONS;i++){
        if(strcmp(questions[i].category, category) == 0  && questions[i].value == value){
            printf("Correct Response: %s IS %s\n", questions[i].begin, questions[i].answer);
            break;
        }
    }
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value){
    // lookup the question and see if it's already been marked as answered
    bool answered = false;

    for(int i=0; i <NUM_QUESTIONS;i++){
        if(strcmp(questions[i].category, category) == 0  && questions[i].value == value){
            if(questions[i].answered == true){
                questions[i].value = 0;
                answered = true;
                break;
            }
        }
    }
    return answered;
}
