#include <stdio.h>
#include <string.h>
#include "myGrep.h"
LinkedList *breakApartLine(char *line, char *search, LinkedList *listPtr, int lineNum);
void copyArray(char *a, char*b);

int main( int argc, char *argv[] )  {
	FILE * input;
	char *result;
	char line[100];
	char *longestLine;
	int numChars;
	int numLines;

	LinkedList list[100];
	LinkedList *listPtr;
	listPtr = &list[0];

    if( argc == 3 ) {
    	printf("\nThe arguments supplied are %s %s\n\n", argv[1], argv[2]);
    	input = fopen(argv[1], "r");
    	result = fgets(line, 99, input);

    	numChars = strlen(line);
		longestLine = line;
		numLines = 1;
    	listPtr = breakApartLine(line, argv[2], listPtr, numLines);

		char *ptr;
		ptr = strtok(line, " ?,!.");
		int wordLoc = 0;
		while(ptr) {
			wordLoc++;
			printf("%s\n", ptr);
			if(strcmp(ptr, argv[2]) == 0) {
		        listPtr = breakApartLine(line, argv[2], listPtr, numLines);
		    }
		}
	}
    printf("\nText In longest lint: %s\n", longestLine);
    printf("Num chars in longest line: %d\n", numChars);
    printf("number of lines: %d\n", numLines);

    printf("\nlinked list stuff:\n");

    printf("%s\n", list[0].line);
    printf("%d\n", list[0].lineNumber);
    printf("%d\n\n", list[0].wordLoc);

}

LinkedList * breakApartLine(char *line, char *search, LinkedList *listPtr, int lineNum) {
	char *ptr;
	ptr = strtok(line, " ?,!."); 
	int wordLoc = 0;
	while(ptr) {
		printf("\nptr: %s", ptr);
		printf(" | search: %s\n", search);
		wordLoc++;
		if(strcmp(ptr, search) == 0) {
			printf("found word: %s\n", ptr);
			//copyArray(&((*listPtr).line), ptr);
			(*listPtr).lineNumber = lineNum;
			(*listPtr).wordLoc= wordLoc;
			listPtr++;
		}
		ptr = strtok(NULL, " ?,!.");
	}
	printf("end breakApartLine\n");
	return listPtr;
}

void copyArray(char *newLoc, char *word) {
	while(*word) {
		*newLoc = *word;
		word++;
		newLoc++;
	}
}
