#include <stdio.h>
#include <stdlib.h>
#include "Lab5_functions.h"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define INIT_CAPACITY 100

void printErrorMessage(char message[]) {
    puts("--------------------------------------------------------------------");
    printf(RED "%s\n" RESET, message);
    puts("--------------------------------------------------------------------");
}

int intInputCheck(int *element) {
    char symbol;

	if (scanf_s("%d%c", element, &symbol) == 2 && symbol == '\n') {
        return 1;
    }

    while (getchar() != '\n');

    return 0;
}

int naturalIntInputCheck(int *element) {
    char symbol;

	if (scanf_s("%d%c", element, &symbol) != 2 || symbol != '\n') {
        while (getchar() != '\n');
        return 0;
    }
    else if (*element <= 0) {
        return 0;
    }
    
    return 1;
}

void isNum(int *input) {
    while (1) {
        if (intInputCheck(input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number.");
    }
}

void isNaturalNum(int *input) {
    while (1) {
        if (naturalIntInputCheck(input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a natural number.");
    }
}

Stack* push(Stack *begin, int info) {
    Stack* t = (Stack*)malloc(sizeof(Stack));
    t->next = begin;
    t->info = info;
    return t;
}

int peek(Stack *begin) {
    if (!(begin)) {
        puts("Stack is empty!");
        return -1;
    }
    else {
        return begin->info;
    }
}

int pop(Stack **begin) {
    if (!(*begin)) {
        puts("Stack is empty!");
        return -1;
    }

    Stack *temp = *begin;

    int info = (*begin)->info;
    *begin = (*begin)->next;

    free(temp);

    return info;
}

void freeStack(Stack **begin) {
    if(begin == NULL) return;

    Stack *temp = *begin;

    while(*begin) {
        *begin = (*begin)->next;
        free(temp);
        temp = *begin;
    }

}

void viewStack(Stack* begin) {
    Stack* temp = begin;

    while(temp) {
        printf("Element = %d\n", temp->info);
        temp = temp->next;
    }
    puts("");
}

int isEmpty(Stack* begin) {
    return begin == NULL;
}

void outputElementsFromStack1ThatAreMetTwoTimesInStack2(Stack* begin1, Stack* begin2) {
    int count = 0, t1 = 0, t2 = 0;

    Stack* begin1_copy = NULL;
    Stack* begin2_copy = NULL;

    while (!isEmpty(begin1)) {
        t1 = pop(&begin1);

        while (!isEmpty(begin2)) {
            t2 = pop(&begin2);
            begin2_copy = push(begin2_copy, t2);

            if(t1 == t2) {
                count++;
            }
        }

        if(count > 2) {
            printf("%d\n", t1);
        }

        count = 0;

        begin1_copy = push(begin1_copy, t1);

        while (!isEmpty(begin2_copy)) {
            t2 = pop(&begin2_copy);
            begin2 = push(begin2, t2);
        }
    }

    while (!isEmpty(begin1_copy)) {
        t1 = pop(&begin1_copy);
        begin1 = push(begin1, t1);
    }

    while (!isEmpty(begin2_copy)) {
        t2 = pop(&begin2_copy);
        begin2 = push(begin2, t2);
    }
}

void insertDescending(Stack** result, int value) {
    Stack* temp = NULL;

    while (!isEmpty(*result) && peek(*result) > value) {
        temp = push(temp, pop(result));
    }

    *result = push(*result, value);

    while (!isEmpty(temp)) {
        *result = push(*result, pop(&temp));
    }
}

Stack* mergeStacksToDescending(Stack* desc_stack, Stack* asc_stack) {
    Stack* result = NULL;

    while (!isEmpty(desc_stack)) {
        insertDescending(&result, pop(&desc_stack));
    }

    while (!isEmpty(asc_stack)) {
        insertDescending(&result, pop(&asc_stack));
    }

    return result;
}

size_t mstrcspn(const char *str1, const char *str2) {
    size_t i = 0;
    while (str1[i]) {
        const char *p = str2;
        while (*p) {
            if (str1[i] == *p)
                return i;
            p++;
        }
        i++;
    }
    return i;
}

int lineLength(char *line) {

	int len = 0;
    while (line[len]) {
		++len;
	}

    return len;
}

void push_double(DoubleStack** begin, double info) {
    DoubleStack* new_begin = (DoubleStack*)malloc(sizeof(DoubleStack));
    new_begin->info = info;
    new_begin->next = *begin;
    *begin = new_begin;
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

int isSpace(char c) {
    return c == ' ';
}

double matof(const char *str) {
    double result = 0.0;
    double fraction = 0.0;
    int sign = 1;
    int divisor = 1;

    while (isSpace(*str)) str++;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (isDigit(*str)) {
        result = result * 10.0 + (*str - '0');
        str++;
    }

    if (*str == '.') {
        str++;
        while (isDigit(*str)) {
            fraction = fraction * 10.0 + (*str - '0');
            divisor *= 10;
            str++;
        }
        result += fraction / divisor;
    }

    return sign * result;
}

int isEmptyD(DoubleStack* begin) {
    return begin == NULL;
}

int isEmptyC(CharStack* begin) {
    return begin == NULL;
}

double pop_double(DoubleStack** begin) {
    if (isEmptyD(*begin)) {
        return 0;
    }

    DoubleStack* temp = *begin;
    double info = temp->info;
    *begin = temp->next;
    
    free(temp);
    return info;
}

void push_char(CharStack** begin, char info) {
    CharStack* new_begin = (CharStack*)malloc(sizeof(CharStack));

    new_begin->operation = info;
    new_begin->next = *begin;
    *begin = new_begin;
}

char pop_char(CharStack** begin) {
    if (isEmptyC(*begin)) {
        return 0;
    }

    CharStack* temp = *begin;
    char info = temp->operation;
    *begin = temp->next;
    free(temp);
    return info;
}

char peek_char(CharStack* begin) {
    return begin ? begin->operation : '\0';
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int operation(char operation) {
    return (operation == '+' || operation == '-') ? 1 : (operation == '*' || operation == '/') ? 2 : 0;
}

int infix_to_postfix(const char* expression, char* output, int* error_spot) {
    CharStack* ops = NULL;
    int i = 0, out = 0;

    while (expression[i]) {
        if (expression[i] == ' ') {
            i++;
            continue;
        }

        if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
            while ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
                output[out++] = expression[i++];
            }
            output[out++] = ' ';
            continue;
        }

        if (is_operator(expression[i])) {
            while (ops && operation(peek_char(ops)) >= operation(expression[i])) {
                output[out++] = pop_char(&ops);
                output[out++] = ' ';
            }
            push_char(&ops, expression[i]);
            i++;
            continue;
        }

        if (expression[i] == '(') {
            push_char(&ops, expression[i]);
            i++;
            continue;
        }

        if (expression[i] == ')') {
            while (ops && peek_char(ops) != '(') {
                output[out++] = pop_char(&ops);
                output[out++] = ' ';
            }

            if (!ops || pop_char(&ops) != '(') {
                *error_spot = i;
                return 0;
            }
            i++;
            continue;
        }

        *error_spot = i;
        return 0;
    }

    while (ops) {
        output[out++] = pop_char(&ops);
        output[out++] = ' ';
    }

    output[out] = '\0';
    return 1;
}

int evaluate_postfix(const char* expression, double* result) {
    DoubleStack* stack = NULL;
    char token[64];
    int i = 0;

    while (expression[i]) {
        if (expression[i] == ' ') {
            i++;
            continue;
        }

        if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
            int j = 0;
            while ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
                token[j++] = expression[i++];
            }
            token[j] = '\0';
            push_double(&stack, matof(token));
            continue;
        }

        if (is_operator(expression[i])) {
            if (isEmptyD(stack) || isEmptyD(stack->next)) {
                return 0;
            }

            double b = pop_double(&stack);
            double a = pop_double(&stack);
            double res = 0;

            if (expression[i] == '/' && b == 0) {
                return -1;
            }
            switch (expression[i]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            push_double(&stack, res);
            i++;
            continue;
        }

        return 0;
    }

    if (isEmptyD(stack) || !isEmptyD(stack->next)) {
        return 0;
    }

    *result = pop_double(&stack);
    return 1;
}