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
    questions[0] = {categories[0], "A ball of gas", "star", 200, false};
    questions[1] = {categories[0], "Only planet to have life", "Earth", 400, false};
    questions[2] = {categories[0], "A ball of gas", "star", 600, false};
    questions[3] = {categories[0], "A ball of gas", "star", 800, false};
    questions[4] = {categories[1], "A ball of gas", "star", 200, false};
    questions[5] = {categories[1], "A ball of gas", "star", 400, false};
    questions[6] = {categories[1], "A ball of gas", "star", 600, false};
    questions[7] = {categories[1], "A ball of gas", "star", 800, false};
    questions[8] = {categories[2], "A ball of gas", "star", 200, false};
    questions[9] = {categories[2], "A ball of gas", "star", 400, false};
    questions[10] = {categories[2], "A ball of gas", "star", 600, false};
    questions[11] = {categories[2], "A ball of gas", "star", 800, false};
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
