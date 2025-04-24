// gcc -c Lab5_lib/Lab5_functions.c -o Lab5_lib/Lab5_functions.o
// ar rcs Lab5_lib/libLab5.a Lab5_lib/Lab5_functions.o
// gcc Lab5.c -LLab5_lib -lLab5 -o Lab5.exe
// В минус минус

#ifndef LAB5_FUNCTIONS_H
#define LAB5_FUNCTIONS_H

typedef struct Stack{
    int info;
    struct Stack *next;
} Stack;

typedef struct DoubleStack {
    double info;
    struct DoubleStack *next;
} DoubleStack;

typedef struct CharStack {
    char operation;
    struct CharStack* next;
} CharStack;

void printErrorMessage(char message[]);
int intInputCheck(int *element);
int naturalIntInputCheck(int *element);
int naturalIntInputCheck0(int *element);
void isNum(int *input);
void isNaturalNum(int *input);
void isNaturalNum0(int *input);
Stack* push(Stack *begin, int info);
int peek(Stack *begin);
int pop(Stack **begin);
void freeStack(Stack **begin);
void viewStack(Stack* begin);
int isEmpty(Stack* begin);
void outputElementsFromStack1ThatAreMetTwoTimesInStack2(Stack* begin1, Stack* begin2);
void insertDescending(Stack** result, int value);
Stack* mergeStacksToDescending(Stack* desc_stack, Stack* asc_stack);
size_t mstrcspn(const char *str1, const char *str2);
int lineLength(char *line);
void push_double(DoubleStack** begin, double info);
int isDigit(char c);
int isSpace(char c);
double matof(const char *str);
int isEmptyD(DoubleStack* begin);
int isEmptyC(CharStack* begin);
double pop_double(DoubleStack** begin);
void push_char(CharStack** begin, char info);
char pop_char(CharStack** begin);
char peek_char(CharStack* begin);
int is_operator(char c);
int operation(char operation);
int infix_to_postfix(const char* expression, char* output, int* error_spot);
int evaluate_postfix(const char* expression, double* result);
Stack* createDescStack(Stack* begin, int size);
Stack* createAscStack(Stack* begin, int size);
Stack* createStack(Stack* begin, int size);
void menuOption1();
void menuOption2();
void menuOption3();

#endif