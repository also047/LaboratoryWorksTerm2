/**
 * Для целого числа (int) вывести содержимое страшего байта (в десятичной системе счисления).
 * Ковалевский
 * 16.03.2025
*/

/**
 * В структуре память выглядит как слова.
 * В зависимости от системы, слова могут быть 4 байта, 2 байта и т. д. (у меня 4 байта).
 * Если ввести int, int, int, char, char, char, то структура займёт 16 байтов.
 * Если же ввести int, char, int, char, то структура займёт 16 байтов, т. к. char займёт в структуре слово длиной в 4 байта несмотря на то,
 * что он сам занимает только 1 байт.
 * В полях бит мы пользуемя unsigned int, т. к. в int первый байт уходит на знак, поэтому если выделить под int 1 бит и инициализировать как его как 1,
 * то запишется на самом деле -1.
 * Когда мы обращаемся к переменной, разделённой на несколько слов, то проходит столько же циклов, сколько и слов. Например, если int разделён по двум "словам",
 * то сначала идёт обращение к первой части intа, а потом к другой в другом слове. Поэтому для разных типов данных, выделяются отдельные слова,
 * чтобы не проходить лишние циклы для получения значения из памяти.
 * Есть две реализации битовых полей, одна с union, другая без
*/

#include <stdio.h>
#include <conio.h>
#include "../Lab3/Lab3_lib/Lab3_functions.h"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

typedef union {
    int value;
    struct {
        unsigned int byte0:8;
        unsigned int byte1:8;
        unsigned int byte2:8;
        unsigned int byte3:8;
    } bytes;
} IntBytes;

void printErrorMessage(char message[]) {
    puts("--------------------------------------------------------------------");
    printf(RED "%s\n" RESET, message);
    puts("--------------------------------------------------------------------");
}

int intInputBytesCheck(IntBytes *element) {
    char symbol;

	if (scanf_s("%d%c", element, &symbol) == 2 && symbol == '\n') {
        return 1;
    }

    while (getchar() != '\n');

    return 0;
}

void isBytesNum(IntBytes *input) {
    while (1) {
        if (intInputBytesCheck(input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number.");
    }
}

int main() {
    IntBytes num;
    int input;

    do {
        printf("Enter an integer: ");
        isBytesNum(&num);
        
        printf("High byte: %d\n", num.bytes.byte3);
        
    } while (puts("\n'r' - Retry | Any key - Exit.\n"), _getch() == 'r');
    
    return 0;
}