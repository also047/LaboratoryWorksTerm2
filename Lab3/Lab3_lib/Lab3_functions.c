#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Lab3_functions.h"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void printErrorMessage(char message[]) {
    puts("--------------------------------------------------------------------");
    printf(RED "%s\n" RESET, message);
    puts("--------------------------------------------------------------------");
}

int intInputCheck(int *element) {
    char symbol;

	if (scanf_s("%d%c", element, &symbol) == 2 && symbol == '\n') {
        return 1;
    }

    while (getchar() != '\n');

    return 0;
}

int intInputBytesCheck(IntBytes *element) {
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
    else if (*element <= 0) {
        return 0;
    }
    
    return 1;
}

void isNum(int *input) {
    while (1) {
        if (intInputCheck(input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number.");
    }
}

void isBytesNum(IntBytes *input) {
    while (1) {
        if (intInputBytesCheck(input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number.");
    }
}

void isNaturalNum(int *input) {
    while (1) {
        if (naturalIntInputCheck(input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a natural number.");
    }
}

void line_input(char **line) {
    size_t size = 0;
    char ch;

    *line = NULL;

    while ((ch = getchar()) != '\n') {
        char *temp = (char *)realloc(*line, size + 2);
        if (temp == NULL) {
            printErrorMessage("Failed to allocate memory for line!");
            free(*line);
            exit(1);
        }

        *line = temp;
        (*line)[size++] = ch;
    }

    if (*line) {
        (*line)[size] = '\0';
    } else {
        *line = (char *)malloc(1);
        if (*line == NULL) {
            printErrorMessage("Memory allocation failed!");
            exit(1);
        }
        (*line)[0] = '\0';
    }
}

int strCmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return !(*(unsigned char *)str1 - *(unsigned char *)str2);
}

void removeFootballTeam(FootballTeam **array, int *size, int ind) {
    if (ind < 0 || ind >= *size) {
        printErrorMessage("Invalid index");
        return;
    }
    
    for (int i = ind; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }
    
    *size -= 1;
    *array = realloc(*array, (*size) * sizeof(FootballTeam));
    if (*size > 0 && *array == NULL) {
        printErrorMessage("Memory reallocation failed");
        exit(1);
    }
}

FootballTeam In() {
    FootballTeam team;
    printf("Name: ");
    line_input((void *)&team.name);

    printf("Wins: ");
    while (1) {
        if (intInputCheck((void *)&team.wins) && team.wins >= 0) {
            break;
        }

        printErrorMessage("Invalid input! Enter an integer from 0.");
    }

    return team;
}

void Out(FootballTeam team) {
    printf("Name: %s\tWins: %d\n", team.name, team.wins);
}

void OutputTeams(FootballTeam *teams, int size) {
    for (size_t i = 0; i < size; i++) {
        printf("Team %d\n", i + 1);
        Out(*(teams + i));
    }
}

FootballTeam* InputTeams(FootballTeam *teams, int size) {
    puts("\nInput teams");
    for (size_t i = 0; i < size; i++) {
        printf("\nTeam %d\n", i + 1);
        teams[i] = In();
    }
    return teams;
}

void allocateMemory(FootballTeam **teams, int size) {
    *teams = (FootballTeam *)malloc(size * sizeof(FootballTeam));
    if (!(*teams)) {
        printErrorMessage("Memory allocation failed!");
        exit(1);
    }
}

void freeMemory(FootballTeam *teams, int size) {
    for (size_t i = 0; i < size; i++) {
        free(teams[i].name);
    }
    free(teams);
}

void outputWordsLongerThanSpecified(FootballTeam* teams, int size) {
    int win_count = 0;

    puts("\nEnter a num of wins: ");
    isNum(&win_count);

    puts("\nTeams");
    for(size_t i = 0; i < size; i++) {
        if(teams[i].wins > win_count) {
            Out(teams[i]);
        }
    }
}

void deleteTeamsWithSpecifiedLength(FootballTeam* teams, int *size) {
    char *name;

    puts("\nEnter the name of the teams to be deleted: ");
    line_input(&name);

    for(size_t i = 0; i < *size; ) {
        if(strCmp(name, teams[i].name)) {
            removeFootballTeam(&teams, size, i);
        }
        else {
            i++;
        }
    }

    puts("\nRemaining teams: ");
    OutputTeams(teams, *size);
}