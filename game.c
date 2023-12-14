#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "wordle.h"

GameState startGame(char word[MAX_WORD_LENGTH + 1]) {
	printf("%s\n", word);
	GameState state = { word };
	char guess[MAX_WORD_LENGTH + 1];
	while (state.guessCount < 6) {
		// guess the word
		scanf("%s", &guess);
		printf("\x1b[1F"); // Move to beginning of previous line
		printf("\x1b[2K"); // Clear entire line
		for (int i = 0; i < strlen(guess); i++) {
			if (guess[i] == word[i]) {
				// Green
				printf("\033[0;102m%c", guess[i]);
				state.guessResult[state.guessCount][i] = GREEN;
			} else {
				if (strchr(word, guess[i]) != NULL) {
					// Yellow
					printf("\033[0;103m%c", guess[i]);
					state.guessResult[state.guessCount][i] = YELLOW;
				} else {
					// white
					printf("\033[0;107m%c", guess[i]);
					state.guessResult[state.guessCount][i] = WHITE;
				}
			}
		}

		state.guessCount++;

		// Reset Color
		printf("\033[0m\n");
		if (strcmp(guess, word) == 0) {
			printf("You win!\n");
			state.success = 1;
			break;
		} else {
			if (state.guessCount < 6)
				printf("Try again!\n");
			else
				printf("Game over!\n");
				state.success = 0;
		}
	}

	return state;
}