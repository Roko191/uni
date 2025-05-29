#pragma once 

#include "../../lib/src/err.h"

typedef struct {
    int a;
    int b;
} Nums;

typedef struct{
    int multiply;
    float division;
    int sum;
    int diff;
} Results;

typedef struct {
    int day;
    int month;
    int year;
} Date;

void flushInputBuff();
char* createHeapString();

// ZADARAK 1.
int* createAndFillArray(int elCnt);
int printArray(int *arr, int elCnt);
char* createAndFillCharArray(int elCnt);
int printCharArray(char* charArr, int elCnt);

// ZADATAK 2.
Nums* getData();
Results* calcMathResults(Nums* data);

// ZADATAK 3.
Date* getDate();
void printDateBeforeAndAfter(Date* datum);

// ZADATAK 4.
void getString(char **str);
void getSubString(char **str);
int countSubstrOccurrences(char *strig, char *sub);