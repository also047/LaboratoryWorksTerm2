/**
 * Создать два стека для целых чисел. Максимальные размеры стеков вводится с экрана.
   Вывести из второго стека все элементы которые встречаются в первом стеке более 2 раз.
 * Ковалевский
 * 05.04.2025
*/

#include <stdio.h>
#include "../Lab5/Lab5_lib/Lab5_functions.h"

int main() {
    Stack *begin1 = NULL, *begin2 = NULL;
    int size1 = 0, size2 = 0, input = 0;

    puts("\nEnter a num of elements for stack 1: ");
    isNaturalNum(&size1);

    for(size_t i = 0; i < size1; i++) {
        printf("Info %zu = ", i + 1);
        isNum(&input);
        begin1 = push(begin1, input);
    }

    puts("\nEnter a num of elements for stack 2: ");
    isNaturalNum(&size2);

    for(size_t i = 0; i < size2; i++) {
        printf("Info %zu = ", i + 1);
        isNum(&input);
        begin2 = push(begin2, input);
    }

    puts("Elements from stack 2 that exist more than 2 times in stack 1: ");
    outputElementsFromStack1ThatAreMetTwoTimesInStack2(begin2, begin1);

    freeStack(&begin1);
    freeStack(&begin2);

    return 0;
}