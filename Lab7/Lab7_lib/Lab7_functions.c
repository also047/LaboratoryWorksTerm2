#include <stdio.h>
#include <stdlib.h>
#include "Lab7_functions.h"

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

// Функция создания узла
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Вставка узла в дерево
Node* insert(Node* root, int value) {
    if (!root) return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Удаление узла из дерева
Node* findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

Node* deleteNode(Node* root, int value) {
    if (!root) return NULL;
    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Поиск последнего уровня с положительными значениями
void findLastPositiveLevel(Node* root, int level, int* maxLevel) {
    if (!root) return;
    if (root->value > 0 && level > *maxLevel)
        *maxLevel = level;
    findLastPositiveLevel(root->left, level + 1, maxLevel);
    findLastPositiveLevel(root->right, level + 1, maxLevel);
}

// Визуализация дерева (рекурсивная печать с отступами)
void printTree(Node* root, int space) {
    if (!root) return;
    space += 5;
    printTree(root->right, space);
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->value);
    printTree(root->left, space);
}

// Освобождение памяти
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}