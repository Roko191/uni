#pragma once

#include <stdio.h>
#include "../../lib/src/err.h"

typedef struct {
    char* name;
    char* surname;
} Person;


// Utils func
char *strlwr(char *str);
char* createHeapString();
void errPrint(int err);
int getFile(FILE** file, char* mode);
void flushInputBuff();

// Zadatak 1
int copyFileContent(FILE* src, FILE* dst);

// Zadatak 2.
int printParsedNumber(FILE* stream);

// Zadatak 3.
int readDataFromFile(FILE* stream, Person*** persons, int* pCnt);
int countPeopleWithFirstName(Person** persons,char* name,int pCnt, int* count);

// Zadatak 4.
int printLineByLineWordByWord(FILE* stream);