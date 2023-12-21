#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "game.h"
#include "file.h"
#include "wordle.h"


int main() {
	srand((unsigned)time(NULL));

	// Worlde dictionary file
	static const char filename[] = "testdict.txt";
	FILE* file = fopen(filename, "r");

	// History file
	FILE* history_file = fopen("history.txt", "a");

	char menu_option = '\0';

	do {
		printf("---------- Wordle ----------\n");
		printf("Main Menu\n");
		printf("a. Start game.\n");
		printf("b. Show history.\n");
		printf("c. Clear history.\n");
		printf("q. Quit the game.\n");
		printf("Please enter an option:");
		scanf(" %c", &menu_option);

		switch (menu_option) {
			case 'a':
				// Get the number of lines in the file
				int lc = lineCount(file);
				//printf("lc = %d\n", lc);
				// Generate a random number between 1 and the number of lines in the file
				int r = rand() % lc;
				//printf("r = %d\n", r);
				// Reset the file pointer to the beginning of the file
				rewind(file);
				// Get the word at the random line number
				char line[MAX_WORD_LENGTH + 1];
				while (r >= 0) {
					fgets(line, sizeof(line), file);
					r--;
				}
				// Remove the newline character from the end of the string
				line[strcspn(line, "\n")] = 0;

				GameState result = startGame(line);

				printf("Answer is: %s\n", result.word);

				char player_name[20];
				printf("Please enter your name:");
				rewind(stdin);
				scanf("%s", &player_name);
				fprintf(history_file, "%s %s %d ", player_name, result.word, result.guessCount);
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 5; j++) {
						fprintf(history_file, "%d ", result.guessResult[i][j]);
					}
				}
				fprintf(history_file, "%d\n", result.success);

				break;
			case 'b':
				showHistory();
				break;
			case 'c':
				clearHistory();
				break;
			case 'q':
				printf("Bye\n");
				break;
			default:
				printf("Invalid option, please retry.");
				break;
		}
	} while (menu_option != 'q');

    fclose(file);
	fclose(history_file);

	return 0;
}



