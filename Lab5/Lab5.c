/**
 * Создать два стека для целых чисел. Максимальные размеры стеков вводится с экрана.
   Вывести из второго стека все элементы которые встречаются в первом стеке более 2 раз.
 * Создать два стека для целых чисел. Первый стек – организовать ввод по убыванию, второй
   стек – организовать ввод по возрастанию. Без сортировок и переворачивания исходных
   стеков сформировать третий стек упорядоченный по убыванию
 * В текстовом файле записаны строки – арифметические выражения. Числа – вещественные,
   знаки действий - -, +, *, / и скобки (). Используя работу со стеками найти значение каждого выражения
   и записать в файл результатов. Если в исходном файле в строке есть ошибка – найти ее предполагаемую
   позицию (позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N»
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
        puts("2. Create a third stack ordered in descending order from descending and ascending stacks");
        puts("3. Find the value of each expression and write it to the results file");
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