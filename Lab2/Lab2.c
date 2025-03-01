#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../Lab2_lib/Lab2_functions.h"

void task_1(const char *filename) {
    do {
        inputTextFile(filename);
        outputTextFile(filename);
	} while (puts("\n1 - Retry | Any key - Back.\n"), _getch() == '1');
}

void task_2(const char *filename) {
    do {
        inputTextFile(filename);
        outputTextFile(filename);
        findWordsWithSpecifiedLength(filename);
    } while (puts("\n1 - Retry | Any key - Back.\n"), _getch() == '1');
}

void task_3(const char *filename) {
    do {
        inputTextFile(filename);
        outputTextFile(filename);
        reverseWordsWithLengthHigherThanSpecified(filename);
    } while (puts("\n1 - Retry | Any key - Back.\n"), _getch() == '1');
}

int main(int argc, char *args[]) {
    if (argc < 2) {
        printErrorMessage("Not enough arguments!");
        return 1;
    }

    void (*input_tasks[])(const char *filename) = {task_1, task_2, task_3};
	int tasks_count = sizeof(input_tasks) / sizeof(input_tasks[0]);

    do {
	    puts("Enter 1 to run task 1\nEnter 2 to run task 2\nEnter 3 to run task 3");

        choose_task(input_tasks, tasks_count, args[1]);

    } while (puts("\n'r' - Retry | Any key - Exit.\n"), _getch() == 'r');

    return 0;
}





// do {
    //     puts("\nEnter 1 to run task 1\nEnter 2 to run task 2\nEnter 3 to run task 3");

    //     int input = 0;

    //     while(1) {
    //         if (intInputCheck(&input) && input >= 1 && input <= 3) {    
    //             break;
    //         }
    //         else {
    //             printErrorMessage("Invalid input! Please, enter a number.");
    //         }
    //     }

    //     if (input == 1) {
    //         task_1(args[1]);
    //     }
    //     else if (input == 2){
    //         task_2(args[1]);
    //     }
    //     else {
    //         task_3(args[1]);
    //     }