#include <stdio.h>
#include <stdlib.h>
#include "Lab6_functions.h"

#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void printErrorMessage(char message[]) {
    puts("--------------------------------------------------------------------");
    printf(RED "%s\n" RESET, message);
    puts("--------------------------------------------------------------------");
}

int isDigit(char c) {
    return c >= '0' && c <= '9';
}

void line_input(char **line) {
	size_t size = 0;
	size_t len = 0;
	char ch;

	while((ch = getchar()) != '\n') {
		char *temp = (char *)realloc(*line, size + 1);

		if (temp == NULL) {
			printErrorMessage("Failed to allocate memory for line!");
			free(*line);
			exit(1);
		}

		*line = temp;
		(*line)[size++] = ch;

		if (*line != NULL) {
			*line = (char *)realloc(*line, size + 1);
			if (*line == NULL) {
				printErrorMessage("Failed to allocate memory for line!");
				exit(1);
			}

			(*line)[size] = '\0';
		}
	}
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

int naturalIntInputCheck0(int *element) {
    char symbol;

	if (scanf_s("%d%c", element, &symbol) != 2 || symbol != '\n') {
        while (getchar() != '\n');
        return 0;
    }
    else if (*element < 0) {
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

void isNaturalNum0(int *input) {
    while (1) {
        if (naturalIntInputCheck0(input)) {
            break;
        }

        printErrorMessage("Invalid input! Enter a natural number.");
    }
}

void addElementQueue(Queue** front, Queue** end, int value) {
    Queue* newEl = (Queue*)malloc(sizeof(Queue));
    newEl->info = value;
    newEl->next = NULL;

    if (!(*end)) {
        *front = *end = newEl;
    } else {
        (*end)->next = newEl;
        *end = newEl;
    }
}

void enterQueue(Queue** front, Queue** end, int size) {
    int value = 0;

    for (int i = 0; i < size; i++) {
        printf("Element #%d: ", i + 1);
        isNum(&value);
        addElementQueue(front, end, value);
    }
}

int removeElementQueue(Queue** front, Queue** end) {
    if (!(*front)) {
        printf("Queue is empty.\n");
        return -1;
    }

    Queue* temp = *front;
    int value = temp->info;
    *front = (*front)->next;

    if (!(*front))
        *end = NULL;

    free(temp);
    return value;
}

void printQueue(Queue* front) {
    printf("Queue elements: ");

    while (front) {
        printf("%d ", front->info);
        front = front->next;
    }
    puts("\n");
}

void printFirstTwoNegatives(Queue* front) {
    int count = 0;
    while (front && count < 2) {
        if (front->info < 0) {
            printf("Negative number #%d: %d\n", count + 1, front->info);
            count++;
        }
        front = front->next;
    }

    if (count == 0) {
        puts("No negative numbers found.");
    }
    else if (count == 1) {
        puts("Only one negative number found.");
    }
}

void clearQueue(Queue** front, Queue** end) {
    while (*front) {
        removeElementQueue(front, end);
    }
}

void addElementDeque(Deque** front, Deque** end, int value) {
    Deque* newEl = (Deque*)malloc(sizeof(Deque));
    newEl->info = value;
    newEl->next = NULL;
    newEl->prev = *end;

    if (!(*end)) {
        *front = *end = newEl;
    } else {
        (*end)->next = newEl;
        *end = newEl;
    }
}

void enterDeque(Deque** front, Deque** end, int size) {
    int value = 0;

    for (int i = 0; i < size; i++) {
        printf("Element #%d: ", i + 1);
        isNum(&value);
        addElementDeque(front, end, value);
    }
}

int removeElementDeque(Deque** front, Deque** end) {
    if (!(*front)) {
        puts("Queue is empty.");
        return -1;
    }

    Deque* temp = *front;
    int value = temp->info;
    *front = (*front)->next;
    if (*front) {
        (*front)->prev = NULL;
    }
    else {
        *end = NULL;
    }

    if (!(*front)) {
        *end = NULL;
    }
    free(temp);
    return value;
}

void printDeque(Deque* front) {
    printf("Deque elements (left to right): ");

    while (front) {
        printf("%d ", front->info);
        front = front->next;
    }
    puts("\n");
}

void printFirstTwoRightNegatives(Deque* end) {
    int count = 0;

    while (end && count < 2) {
        if (end->info < 0) {
            printf("Negative number from right #%d: %d\n", count + 1, end->info);
            count++;
        }
        end = end->prev;
    }

    if (count == 0) {
        puts("No negative numbers found from the right.");
    }
    else if (count == 1) {
        puts("Only one negative number found from the right.");
    }
}

void clearDeque(Deque** front, Deque** end) {
    while (*front) {
        removeElementDeque(front, end);
    }
}

// Минус учитывается только если перед ним пробел, а после него число, т. е. только, когда он непосрелственно относится к числу.
void extractNumbersAndAddToQueue(const char* str, Queue** front, Queue** end) {
    int num = 0;
    int isNegative = 0;
    int hasNumber = 0;

    while (*str) {
        if (isDigit(*str)) {
            num = num * 10 + (*str - '0');
            hasNumber = 1;
        } 
        else if (*str == '-' && !hasNumber) {
            isNegative = 1;
        } 
        else if (hasNumber) {
            if (isNegative) {
                num = -num;
            }
            addElementQueue(front, end, num);
            num = 0;
            isNegative = 0;
            hasNumber = 0;
        }
        str++;
    }

    if (hasNumber) {
        if (isNegative) {
            num = -num;
        }
        addElementQueue(front, end, num);
    }
}

int calculateSum(Queue* front) {
    int sum = 0;

    while (front) {
        sum += front->info;
        front = front->next;
    }
    return sum;
}

void menuOption1() {
    Queue* front = NULL;
    Queue* end = NULL;
    int size = 0;

    puts("Enter a num of elements for the queue: ");
    isNaturalNum(&size);

    printf("Enter %d integers: \n", size);
    enterQueue(&front, &end, size);

    printQueue(front);
    printFirstTwoNegatives(front);

    clearQueue(&front, &end);
}

void menuOption2() {
    Deque* front = NULL;
    Deque* end = NULL;
    int size = 0;

    puts("Enter a num of elements for the deque: ");
    isNaturalNum(&size);

    printf("Enter %d integers: \n", size);
    enterDeque(&front, &end, size);

    printDeque(front);
    printFirstTwoRightNegatives(end);

    clearDeque(&front, &end);
}

void menuOption3() {
    Queue* front = NULL;
    Queue* end = NULL;
    char *line = NULL;

    puts("Enter a string with numbers: ");
    line_input(&line);

    extractNumbersAndAddToQueue(line, &front, &end);
    printQueue(front);

    int sum = calculateSum(front);
    printf("Sum of the numbers: %d\n", sum);

    clearQueue(&front, &end);
    free(line);
}