#pragma once

#include <stdio.h>
#include "../../lib/src/err.h"

#define NOT_ENOUGH_STUDENTS 100

typedef struct {
    char* name;
    char* surname;
    int first_sem;
    int sec_sem;
} Student;

// Zadatak 1
int getArraySize();
int getArray(int elementNumber, int** array);
int getTagetNumber();
int findNumInArray(int* array, int target, int elementNumber);

// Zadatak 2
int getNumber();
char* formatNumToString(int number, int* digitCount);
int printString(char* string, int digitCount);

// Zadatak 3
int getStudentDataFromFile(Student*** students, FILE* stream, int studnetNum);
int getPointsFromConsole(Student** students, int studentNum);
int getGrade(Student* student);
int printStudentDataToConsole(Student** students, int studentNum);