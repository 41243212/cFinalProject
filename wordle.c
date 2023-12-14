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
	// Get the number of lines in the file
    int lc = lineCount(file);
	printf("lc = %d\n", lc);
	// Generate a random number between 1 and the number of lines in the file
	int r = rand() % lc;
	printf("r = %d\n", r);
	// Reset the file pointer to the beginning of the file
	rewind(file);
	// Get the word at the random line number
	char line[MAX_WORD_LENGTH + 1];
	while (r >= 0) {
		fgets(line, sizeof(line), file);
		r--;
	}
	printf("ans is %s", line);
	// Remove the newline character from the end of the string
	line[strcspn(line, "\n")] = 0;

	GameState result = startGame(line);

	printf("%s\n", result.word);

    fclose(file);
}



