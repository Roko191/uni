#include <stdio.h>
#include <stdlib.h>

#include "../func.h"

void zadatak1(){
    Time* unos1 = malloc(sizeof(Time));
    Time* unos2 = malloc(sizeof(Time)); 

    // Unos 1
    printf("Unesi vrime 1 [HH:MM:SS]: ");
    flushInputBuff();
    char* strUnos1 = createHeapString();

    sscanf(strUnos1, "%d:%d:%d", &unos1->hour, &unos1->minute, &unos1->seconds);

    printf("Vrime 1 (uneseno): %d:%d:%d\n", unos1->hour, unos1->minute, unos1->seconds);

    // Unos 2
    printf("Unesi vrime 2 [HH:MM:SS]: ");
    char* strUnos2 = createHeapString();

    sscanf(strUnos2, "%d:%d:%d", &unos2->hour, &unos2->minute, &unos2->seconds);

    printf("Vrime 2 (uneseno): %d:%d:%d\n", unos2->hour, unos2->minute, unos2->seconds);
 
    
    // Zbroj
    Time* zbroj = zbroji(unos1, unos2);

    printf("Zbroj: %d:%d:%d\n", zbroj->hour, zbroj->minute, zbroj->seconds);

    free(strUnos1);
    free(strUnos2);
}

void zadatak2(){
    printf("Unesi datum [DD.MM.YYYY]: ");
    
    Date* datum = malloc(sizeof(Date));

    flushInputBuff();
    char* strDatum = createHeapString();

    sscanf(strDatum, "%d.%d.%d", &datum->day, &datum->month, &datum->year);

    printf("Datum unesen: %d.%d.%d", datum->day, datum->month, datum->year);
    
    printDateBeforeAndAfter(datum);

    free(datum);

    return;
}
void zadatak3(){
    return;
}