#ifndef LAB2_FUNCTIONS_H
#define LAB2_FUNCTIONS_H

void printErrorMessage(char []);
int intInputCheck(int *);
int naturalIntInputCheck(int *);
void inputIntegerFrom1To100(int *, const char *);
int line_length(char *);
int inputTextFile(const char *);
void outputTextFile(const char *);
void findWordsWithSpecifiedLength(const char *);
void reverseWordsWithLengthHigherThanSpecified(const char *);
void choose_task(void(*[])(const char *), int , const char *);

#endif

/**
 * cd Lab2_lib
 * gcc -c Lab2_functions.c
 * ar rcs libLab2.a Lab2_functions.o
 * cd ..
 * gcc Lab2.c -I./Lab2_lib -L./Lab2_lib -lLab2 -o Lab2
 * ./Lab2 input.txt
*/