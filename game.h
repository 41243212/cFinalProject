#ifndef GAME_H
#define GAME_H

#include "wordle.h"

typedef struct GameState_t {
    char *word; // The word to guess
    int guessCount; // The number of guesses made
    enum GuessResult guessResult[6][5]; // The result of each guess
    int success; // 1 if the word was guessed, 0 if not
} GameState;

enum GuessResult {
    WHITE = 0,
    GREEN = 1,
    YELLOW = 2
};

// Function declarations
GameState startGame(char[]);

#endif