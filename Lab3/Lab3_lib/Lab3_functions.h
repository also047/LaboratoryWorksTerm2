/**
 * gcc -c Lab3_lib/Lab3_functions.c -o Lab3_lib/Lab3_functions.o
 * ar rcs Lab3_lib/libLab3.a Lab3_lib/Lab3_functions.o
 * gcc Lab3.1.c -LLab3_lib -lLab3 -o Lab3.1.exe
 * gcc Lab3.2.c -LLab3_lib -lLab3 -o Lab3.2.exe
*/

#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

// Так как структура данных union использует один и тот же участок памяти, то при изменении значения(value), будут изменяться и байты(bytes)
typedef union {
    int value;
    struct {
        unsigned int byte0:8;
        unsigned int byte1:8;
        unsigned int byte2:8;
        unsigned int byte3:8;
    } bytes;
} IntBytes;

typedef struct {
    int wins;
    char *name;
    struct {
        char year_of_the_last_win[1024];
        int loses; 
    } aditionalInfo;
} FootballTeam;

void printErrorMessage(char []);
int intInputCheck(int *);
int intInputBytesCheck(IntBytes *);
int naturalIntInputCheck(int *);
void isNum(int *);
void isBytesNum(IntBytes *);
void isNaturalNum(int *);
void line_input(char **);
int strCmp(const char *, const char *);
void removeFootballTeam(FootballTeam **, int *, int );
FootballTeam In();
void Out(FootballTeam );
void OutputTeams(FootballTeam *, int );
FootballTeam* InputTeams(FootballTeam *, int );
void allocateMemory(FootballTeam **, int );
void freeMemory(FootballTeam *, int );
void outputWordsLongerThanSpecified(FootballTeam *, int );
void deleteTeamsWithSpecifiedLength(FootballTeam *, int *);

#endif