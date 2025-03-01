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