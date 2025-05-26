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


void flushInputBuff();


// ZADARAK 1.
int* createAndFillArray(int elCnt);
int printArray(int *arr, int elCnt);
char* createAndFillCharArray(int elCnt);
int printCharArray(char* charArr, int elCnt);

// ZADATAK 2.
Nums* getData();
Results* calcMathResults(Nums* data);