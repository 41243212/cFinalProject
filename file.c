#include <stdio.h>
#include <string.h>

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
	return count;
}

void showHistory() {
	printf("todo");
}
void clearHistory() {
	printf("todo");
}
