/**
 * В текстовом файле записаны строки – арифметические выражения. Числа – вещественные,
   знаки действий - -, +, *, / и скобки (). Используя работу со стеками найти значение каждого выражения
   и записать в файл результатов. Если в исходном файле в строке есть ошибка – найти ее предполагаемую
   позицию (позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N».
 * Ковалевский
 * 18.04.2025
*/

#include <stdio.h>
#include "../Lab5/Lab5_lib/Lab5_functions.h"

int main() {
    FILE* in = fopen("expressions.txt", "r");
    FILE* out = fopen("results.txt", "w");

    if (!in || !out) {
        printErrorMessage("Failed to open the file!");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), in)) {
        line[mstrcspn(line, "\n")] = '\0';
        if (lineLength(line) == 0) continue;

        char postfix[512];
        int error_spot;

        if (!infix_to_postfix(line, postfix, &error_spot)) {
            fprintf(out, "Mistake in position %d\n", error_spot + 1);
            continue;
        }

        double result;
        int eval_status = evaluate_postfix(postfix, &result);

        if (eval_status == -1) {
            fprintf(out, "Error: division by 0\n");
        } else if (eval_status == 0) {
            fprintf(out, "Error in expression\n");
        } else {
            fprintf(out, "%.6lf\n", result);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}