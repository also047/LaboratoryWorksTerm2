/**
 * Структура содержит информацию о футбольных командах: количество побед
    (число), название (указатель), вложенную структуру – год последней победы
    (строка фиксированной длины) и количество проигрышей. Найти команды с
    количеством побед больше заданного. Удалить команды с заданным названием.
 * Ковалевский
 * 16.03.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../Lab3/Lab3_lib/Lab3_functions.h"

int main() {
    FootballTeam *teams = NULL;
    int size = 0;

    do {
        printf("Input the number of teams: ");
        isNaturalNum(&size);

        allocateMemory(&teams, size);
        InputTeams(teams, size);
        OutputTeams(teams, size);

        int input = 0;
        do {
            puts("\n1 - Search task | 2 - Delete task.\n");
            isNaturalNum(&input);
    
            if (input == 1) {
                outputWordsLongerThanSpecified(teams, size);
            }
            else if (input == 2) {
                deleteTeamsWithSpecifiedLength(teams, &size);
            }
            else {
                printErrorMessage("Invalid input! Enter a number from 1 to the available options.");
            }

            
        } while (puts("\n'r' - Retry | Any key - Go back.\n"), _getch() == 'r');

        freeMemory(teams, size);
	} while (puts("\n'r' - Retry | Any key - Exit.\n"), _getch() == 'r');

    return 0;
}