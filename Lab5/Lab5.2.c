/**
 * Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй
   стек – организовать ввод по возрастанию. Без сортировок и переворачивания исходных
   стеков сформировать третий стек упорядоченный по убыванию.
 * Ковалевский
 * 05.04.2025
*/

#include <stdio.h>
#include "../Lab5/Lab5_lib/Lab5_functions.h"

int main() {
    Stack *begin1 = NULL, *begin2 = NULL, *begin3 = NULL;
    int size1 = 0, size2 = 0, input = 0;

    puts("\nEnter a num of elements for stack 1: ");
    isNaturalNum(&size1);

    for(size_t i = 0; i < size1; i++) {
        printf("Info %zu = ", i + 1);
        while(1) {
            isNum(&input);
            if(!begin1 || input >= peek(begin1)) {
                begin1 = push(begin1, input);
                break;
            }
            else {
                printErrorMessage("Invalid input! Enter a number higher than a previous one.");
            }
        }
    }

    puts("\nEnter a num of elements for stack 2: ");
    isNaturalNum(&size2);

    for(size_t i = 0; i < size2; i++) {
        printf("Info %zu = ", i + 1);
        while(1) {
            isNum(&input);
            if(!begin2 || input <= peek(begin2)) {
                begin2 = push(begin2, input);
                break;
            }
            else {
                printErrorMessage("Invalid input! Enter a number lower than a previous one.");
            }
        }
    }

    begin3 = mergeStacksToDescending(begin1, begin2);

    puts("\nNew stack: \n");
    viewStack(begin3);
    freeStack(&begin3);

    return 0;
}