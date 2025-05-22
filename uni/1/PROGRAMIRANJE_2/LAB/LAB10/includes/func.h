#pragma once

typedef struct {
    int hour;
    int minute;
    int seconds;
} Time;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char* name;
    char* surname;
    Date* birthday;
    Time* birthtime;
} Person;

// Helper funckije
Date* getDate();
Time* getTime();

int compareDates(Date* a, Date* b);
int compareTimes(Time* a, Time* b);

void flushInputBuff();
char* createHeapString();

// Zadatak 1
Time* zbroji(Time* vrime1, Time* vrime2);

// Zadatak 2
int checkLeapYear(int godina);
Date* calculateDateBefore(Date* datum);
Date* calculateDateAfter(Date* datum);
void printDateBeforeAndAfter(Date* datum);

// Zadatak 3
int getPeopleData(Person* osoba, int arrSize);
Person* findAndPrintOldestPerson(Person* osoba, int arrSize);
Person* findAndPrintAlphaFirstPerson(Person* osoba, int arrSize);
void printPerson(Person* osoba);
void printAllPeople(Person* osoba, int arrSize);