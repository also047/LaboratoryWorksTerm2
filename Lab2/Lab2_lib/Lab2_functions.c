#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "Lab2_functions.h"

#define MAX_SIZE 100
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void printErrorMessage(char message[]) {
    puts("\n-----------------------------------------------");
    printf(RED "%s\n" RESET, message);
    puts("-----------------------------------------------\n");
}

int intInputCheck(int *element) {
    char symbol;

	if (scanf_s("%d%c", element, &symbol) == 2 && symbol == '\n') {
        return 1;
    }

    while (getchar() != '\n');

    return 0;
}

int naturalIntInputCheck(int *element) {
    char symbol;

	if (scanf_s("%d%c", element, &symbol) != 2 || symbol != '\n') {
        while (getchar() != '\n');
        return 0;
    }
    else if (*element < 0) {
        return 0;
    }
    
    return 1;
}

void inputIntegerFrom1To100(int *input, const char *line) {

    while (1) {
        printf("%s", line);

        if (naturalIntInputCheck(input) && *input <= MAX_SIZE) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number from 1 to 100.");
    }
}

int line_length(char *line) {

	int len = 0;
    while (line[len]) {
		++len;
	}

    return len;
}

int inputTextFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int elements;
    char word[256];

    puts("Enter the number of words(<= 100): ");

	inputIntegerFrom1To100(&elements, "");

    puts("Enter words of the file: ");
    for (int i = 0; i < elements; i++) {
        printf("%d: ", i + 1);

        fgets(word, sizeof(word), stdin);

        int len = line_length(word);
        if (len > 0 && word[len - 1] == '\n') {
            word[len - 1] = '\0';
        }

        fprintf(file, "%s\n", word);
    }

    fclose(file);
    return elements;
}

void outputTextFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char word[256];

    puts("\nWords: ");
    while(fscanf(file, "%255s", word) == 1) {
        printf("%s ", word);
    }
    puts("");

    fclose(file);
}

void findWordsWithSpecifiedLength(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int input;

    puts("Enter the length to compare with: ");
    while (1) {
        if (naturalIntInputCheck(&input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number from 1 to 100.");
    }

    char word[256];

    puts("Found words:");
    while (fscanf(file, "%255s", word) == 1) {
        if(input == line_length(word)) {
            printf("%s ", word);
        }
    }
}

void reverseWordsWithLengthHigherThanSpecified(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int input;

    puts("\nEnter the length to compare with: ");
    while (1) {
        if (naturalIntInputCheck(&input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number from 1 to 100.");
    }

    char word[256];
    int ch;
    long start_pos;
    
    while ((ch = fgetc(file)) != EOF) {
        if (!isspace(ch)) {
            start_pos = ftell(file) - 1;
            fseek(file, start_pos, SEEK_SET);
            fscanf(file, "%255s", word);
            int length = line_length(word);
            if (length > input) {
                for (int i = 0; i < length / 2; i++) {
                    long left_pos = start_pos + i;
                    long right_pos = start_pos + length - 1 - i;

                    fseek(file, left_pos, SEEK_SET);
                    char left_char = fgetc(file);

                    fseek(file, right_pos, SEEK_SET);
                    char right_char = fgetc(file);

                    fseek(file, left_pos, SEEK_SET);
                    fputc(right_char, file);

                    fseek(file, right_pos, SEEK_SET);
                    fputc(left_char, file);
                }
            }
            fseek(file, start_pos + length, SEEK_SET);
        }
    }

    fclose(file);
}

void choose_task(void(*input_tasks[])(const char *filename), int tasks_count, const char *filename) {
	int input = 0;

	do {
		intInputCheck(&input);

		if (input >= 1 && input <= tasks_count) {
			input_tasks[input - 1](filename);
		}
		else {
			printErrorMessage("Invalid input! Enter a number from 1 to the available options.");
			input = 0;
		}

	} while (input == 0);
}