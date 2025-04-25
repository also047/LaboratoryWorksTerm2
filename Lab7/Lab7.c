#include <stdio.h>
#include <stdlib.h>
#include "../Lab7/Lab7_lib/Lab7_functions.h"

// Меню
int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Вставить элемент\n");
        printf("2. Удалить элемент\n");
        printf("3. Найти последний уровень с положительными элементами\n");
        printf("4. Визуализация дерева\n");
        printf("5. Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Введите значение для вставки: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Введите значение для удаления: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3: {
                int maxLevel = -1;
                findLastPositiveLevel(root, 0, &maxLevel);
                if (maxLevel >= 0)
                    printf("Последний уровень с положительными элементами: %d\n", maxLevel);
                else
                    printf("Положительные элементы не найдены.\n");
                break;
            }
            case 4:
                printf("Визуализация дерева:\n");
                printTree(root, 0);
                break;
            case 5:
                freeTree(root);
                return 0;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
}