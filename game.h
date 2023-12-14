#ifndef GAME_H
#define GAME_H

typedef struct GameState_t {
    char *word; // The word to guess
    int guessCount; // The number of guesses made
    int guessResult[6][5]; // The result of each guess
    int success; // 1 if the word was guessed, 0 if not
} GameState;


// Function declarations
GameState startGame(char[]);

#endif