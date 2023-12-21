#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "wordle.h"

/*
* Counts the number of lines in a file
*/
int lineCount(FILE* file) {
	int count = 0, ch;
	do {
		ch = fgetc(file);
		if (ch == '\n')
			count++;
	} while (ch != EOF);
	// Reset the file pointer to the beginning of the file
	rewind(file);
	return count;
}

void showHistory(FILE* file) {
	int count = lineCount(file);
	if (count == 0) {
		printf("No history, play the game first!\n");
		return;
	}
	GameState state;
	char player_name[20];
	char word[10];
	for (int i = 0; i < count; i++) {
		fscanf(file, "%s %s %d %d", player_name, &word, &state.guessCount, &state.success);
		state.word = &word;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 5; j++) {
				fscanf(file, " %d", &(state.guessResult[i][j]));
			}
		}
		printf("---------- History ----------\n");
		printf("Player: %s\n", player_name);
		for (int i = 0; i < state.guessCount; i++) {
			for (int j = 0; j < 5; j++) {
				if (state.guessResult[i][j] == WHITE) {
					printf("\033[0;107m ");
				}
				else if (state.guessResult[i][j] == YELLOW) {
					printf("\033[0;103m ");
				}
				else if (state.guessResult[i][j] == GREEN) {
					printf("\033[0;102m ");
				}
				// Reset Color
				printf("\033[0m ");
			}
			printf("\n");
		}
	}
}
void clearHistory(FILE* file) {
	fclose(file);
	printf("Cleared!\n");
}
