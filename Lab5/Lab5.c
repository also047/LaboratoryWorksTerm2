/**
 * Создать два стека для целых чисел. Максимальные размеры стеков вводится с экрана.
   Вывести из второго стека все элементы которые встречаются в первом стеке более 2 раз.
 * 
 * 
 * Ковалевский
 * 05.04.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Lab5/Lab5_lib/Lab5_functions.h"

int main() {
    int choice;

    while (1) {
        puts("\nMenu:");
        puts("1. Remove from the second stack all the elements that occur in the first stack more than 2 times");
        puts("2. Print first two right negatives from deque");
        puts("3. Extract numbers from a string and calculate their sum");
        puts("0. Exit");
        printf("Enter your choice: ");
        isNaturalNum0(&choice);

        switch (choice) {
            case 1:
                menuOption1();
                break;
            case 2:
                menuOption2();
                break;
            case 3:
                menuOption3();
                break;
            case 0:
                exit(0);
                break;
            default:
                printErrorMessage("Invalid choice! Please try again.");
        }
    }

    return 0;
}