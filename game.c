#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "game.h"

GameState startGame(char word[]) {
	printf("%s\n", word);
	GameState state;
	state.word = word;
	char guess[256];
	int guessCount = 0;
	int guessResult[6][5] = { 0 };
	while (guessCount < 6) {
		// guess the word
		scanf("%s", &guess);
		printf("\x1b[1F"); // Move to beginning of previous line
		printf("\x1b[2K"); // Clear entire line
		for (int i = 0; i < strlen(guess); i++) {
			if (guess[i] == word[i]) {
				// Green
				printf("\033[0;102m%c", guess[i]);
				guessResult[guessCount][i] = 1;
			} else {
				if (strchr(word, guess[i]) != NULL) {
					// Yellow
					printf("\033[0;103m%c", guess[i]);
					guessResult[guessCount][i] = 2;
				} else {
					// white
					printf("\033[0;107m%c", guess[i]);
					guessResult[guessCount][i] = 3;
				}
			}
		}
		// Reset Color
		printf("\033[0m\n");
		if (strcmp(guess, word) == 0) {
			printf("You win!\n");
			break;
		} else {
			guessCount++;
			if (guessCount < 6)
				printf("Try again!\n");
			else
				printf("Game over!\n");
		}
	}
	return state;
}