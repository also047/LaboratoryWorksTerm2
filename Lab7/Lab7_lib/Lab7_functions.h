// gcc -c Lab7_lib/Lab7_functions.c -o Lab7_lib/Lab7_functions.o
// ar rcs Lab7_lib/libLab7.a Lab7_lib/Lab7_functions.o
// gcc Lab7.c -LLab7_lib -lLab7 -o Lab7.exe

#ifndef LAB6_FUNCTIONS_H
#define LAB6_FUNCTIONS_H

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

void printErrorMessage(char message[]);
int isDigit(char c);
void line_input(char **line);
int intInputCheck(int *element);
int naturalIntInputCheck(int *element);
int naturalIntInputCheck0(int *element);
void isNum(int *input);
void isNaturalNum(int *input);
void isNaturalNum0(int *input);
Node* createNode(int value);
Node* insert(Node* root, int value);
Node* findMin(Node* node);
Node* deleteNode(Node* root, int value);
void findLastPositiveLevel(Node* root, int level, int* maxLevel);
void printTree(Node* root, int space);
void freeTree(Node* root);

#endif