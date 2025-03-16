/**
 * Для целого числа (int) вывести содержимое страшего байта (в десятичной системе счисления).
 * Ковалевский
 * 16.03.2025
*/

#include <stdio.h>
#include <conio.h>
#include "../Lab3/Lab3_lib/Lab3_functions.h"

int main() {
    IntBytes num;
    int input;

    do {
        printf("Enter an integer: ");
        isBytesNum(&num);
        
        // Старший байт будет ненулевым если число отрицательное или больше 2^32(16 777 215)
        printf("High byte: %d\n", num.bytes.byte3);
        
    } while (puts("\n'r' - Retry | Any key - Exit.\n"), _getch() == 'r');
    
    return 0;
}