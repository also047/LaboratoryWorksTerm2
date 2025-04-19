// gcc -c Lab6_lib/Lab6_functions.c -o Lab6_lib/Lab6_functions.o
// ar rcs Lab6_lib/libLab6.a Lab6_lib/Lab6_functions.o
// gcc Lab6.c -LLab6_lib -lLab6 -o Lab6.exe
// В минус минус

#ifndef LAB6_FUNCTIONS_H
#define LAB6_FUNCTIONS_H

typedef struct Queue {
    int info;
    struct Queue* next;
} Queue;

typedef struct Deque {
    int info;
    struct Deque* next;
    struct Deque* prev;
} Deque;

void printErrorMessage(char message[]);
int isDigit(char c);
void line_input(char **line);
int intInputCheck(int *element);
int naturalIntInputCheck(int *element);
int naturalIntInputCheck0(int *element);
void isNum(int *input);
void isNaturalNum(int *input);
void isNaturalNum0(int *input);
void addElementQueue(Queue** front, Queue** end, int value);
void enterQueue(Queue** front, Queue** end, int size);
int removeElementQueue(Queue** front, Queue** end);
void printQueue(Queue* front);
void printFirstTwoNegatives(Queue* front);
void clearQueue(Queue** front, Queue** end);
void addElementDeque(Deque** front, Deque** end, int value);
void enterDeque(Deque** front, Deque** end, int size);
int removeElementDeque(Deque** front, Deque** end);
void printDeque(Deque* front);
void printFirstTwoRightNegatives(Deque* end);
void clearDeque(Deque** front, Deque** end);
void extractNumbersAndAddToQueue(const char* str, Queue** front, Queue** end);
int calculateSum(Queue* front);
void menuOption1();
void menuOption2();
void menuOption3();

#endif