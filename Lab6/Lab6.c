/**
 * Создать очередь для целых (положительных и отрицательных) чисел. Максимальный размер
   очереди вводится с экрана. Создать функции для ввода и вывода элементов очереди. Ввести 6
   элементов (положительных и отрицательных). Вывести 2 первых отрицательных элемента очереди.
 * Создать дек для целых (положительных и отрицательных) чисел. Максимальный размер дека
   вводится с экрана. Создать функции для ввода и вывода элементов дека. Ввести 6 элементов
   (положительных и отрицательных). Вывести 2 первых правых отрицательных элемента дека.
 * Введите строку. Проанализировав в программе содержимое строки, выберите из нее числа и
   занесите в очередь. Выведите содержимое очереди на экран и посчитайте сумму этих чисел. Решение в
   программе оформляйте через подпрограммы.
 * Ковалевский
 * 19.04.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "../Lab6/Lab6_lib/Lab6_functions.h"

int main() {
    int choice;

    while (1) {
        puts("\nMenu:");
        puts("1. Print first two negatives from queue");
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