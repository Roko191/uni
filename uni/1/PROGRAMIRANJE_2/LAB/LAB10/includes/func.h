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


void flushInputBuff();
char* createHeapString();

Time* zbroji(Time* vrime1, Time* vrime2);

int checkLeapYear(int godina);
Date* calculateDateBefore(Date* datum);
Date* calculateDateAfter(Date* datum);
void printDateBeforeAndAfter(Date* datum);

