#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_SIZE 100
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

void printErrorMessage(char message[]) {
    puts("\n-----------------------------------------------");
    printf(RED "⚠️  %s\n" RESET, message);
    puts("-----------------------------------------------\n");
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
    else if (*element < 0) {
        return 0;
    }
    
    return 1;
}

void inputIntegerFrom1To100(int *input, const char *line) {

    while (1) {
        printf("%s", line);

        if (naturalIntInputCheck(input) && *input <= MAX_SIZE) {
            break;
        }

        printErrorMessage("Invalid input! Enter a number from 1 to 100.");
    }
}

int inputBinFile(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int elements, input;

    puts("Enter the number of elements(<= 100): ");

	inputIntegerFrom1To100(&elements, "");

    puts("Enter elements of the file: ");
    for (size_t i = 0; i < elements; i++) {
        printf("%zu: ", i + 1);

        while(1) {
            if (intInputCheck(&input)) {
                fwrite(&input, sizeof(int), 1, file);
                break;
            }
            else {
                printErrorMessage("Invalid input! Please, enter a number.");
            }
        }
    }

    fclose(file);
    return elements;
}

void outputBinFile(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int input;

    puts("\nElements: ");
    for (size_t i = 0; fread(&input, sizeof(int), 1, file) == 1; i++) {
        printf("%d ", input);

        if (i % 20 == 0 && i != 0) {
			puts("");
		}
    }
    puts("");

    fclose(file);
}

int elementsHigherThanSumOfPrevious(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int sum = 0, num = 0, count = 0;

    if (fread(&num, sizeof(int), 1, file) != 1) {
        fclose(file);
        return 0;
    }

    sum = num;

    while(fread(&num, sizeof(int), 1, file) == 1) {
        if (num > sum) {
            count++;
        }
        sum += num;
    }

    fclose(file);
    return count;
}

void descendingSorting(const char *filename) {
    FILE *file = fopen(filename, "r+b");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    int numOfElements = fileSize / sizeof(int);

    for (size_t i = 0; i < numOfElements - 1; i++) {
        for (size_t j = 0; j < numOfElements - 1 - i; j++) {
            int num1, num2;

            fseek(file, j * sizeof(int), SEEK_SET);
            fread(&num1, sizeof(int), 1, file);

            fseek(file, (j + 1) * sizeof(int), SEEK_SET);
            fread(&num2, sizeof(int), 1, file);

            if (num1 < num2) {
                fseek(file, j * sizeof(int), SEEK_SET);
                fwrite(&num2, sizeof(int), 1, file);

                fseek(file, (j + 1) * sizeof(int), SEEK_SET);
                fwrite(&num1, sizeof(int), 1, file);
            }
        }
    }

    fclose(file);
}

void mergeFiles(const char *filename1, const char *filename2, const char *output) {
    FILE *file1 = fopen(filename1, "rb");
    FILE *file2 = fopen(filename2, "rb");
    FILE *out = fopen(output, "wb");
    
    if (!file1 || !file2 || !out) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    int num1, num2;
    int read1 = fread(&num1, sizeof(int), 1, file1);
    int read2 = fread(&num2, sizeof(int), 1, file2);
    
    while (read1 && read2) {
        if (num1 >= num2) {
            fwrite(&num1, sizeof(int), 1, out);
            read1 = fread(&num1, sizeof(int), 1, file1);
        } else {
            fwrite(&num2, sizeof(int), 1, out);
            read2 = fread(&num2, sizeof(int), 1, file2);
        }
    }
    
    while (read1) {
        fwrite(&num1, sizeof(int), 1, out);
        read1 = fread(&num1, sizeof(int), 1, file1);
    }
    
    while (read2) {
        fwrite(&num2, sizeof(int), 1, out);
        read2 = fread(&num2, sizeof(int), 1, file2);
    }
    
    fclose(file1);
    fclose(file2);
    fclose(out);
}

void task_1(const char *filename) {
    do {
        int input = elementsHigherThanSumOfPrevious(filename);
		puts("\nNumber of elements that are higher than sum of the previous elements: ");
        printf("%d\n", input);

	} while (puts("\n1 - Retry | Any key - Back.\n"), _getch() == '1');
}

void task_2(const char *filename1, const char *filename2) {
    do {
        int elements1 = inputBinFile(filename2);
        outputBinFile(filename2);
        descendingSorting(filename1);
        descendingSorting(filename2);
        outputBinFile(filename1);
        outputBinFile(filename2);

        mergeFiles(filename1, filename2, "NewBinFile.bin");
        outputBinFile("NewBinFile.bin");
    } while (puts("\n1 - Retry | Any key - Back.\n"), _getch() == '1');
}

int main(int argc, char *args[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file> [optional_second_arg]\n", args[0]);
        return 1;
    }

    do {
        int elements = inputBinFile(args[1]);
        outputBinFile(args[1]);

        puts("\nEnter 1 to run task 1\nEnter 2 to run task 2");

        int input = 0;

        while(1) {
            if (intInputCheck(&input) && input >= 1 && input <= 2) {    
                break;
            }
            else {
                printErrorMessage("Invalid input! Please, enter a number.");
            }
        }

        if (input == 1) {
            task_1(args[1]);
        }
        else {
            task_2(args[1], args[2]);
        }

	} while (puts("\n'r' - Retry | Any key - Exit.\n"), _getch() == 'r');
    return 0;
}