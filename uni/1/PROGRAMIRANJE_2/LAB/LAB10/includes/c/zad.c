#include <stdio.h>
#include <stdlib.h>

#include "../func.h"

#define PEOPLE_NUM 5

void zadatak1(){
    printf("\n===ZADATAK 1.===\n");

    flushInputBuff();

    Time* unos1 = getTime();
    Time* unos2 = getTime(); 

    printf("Vrime 1 (uneseno): %d:%d:%d\n", unos1->hour, unos1->minute, unos1->seconds);
    printf("Vrime 2 (uneseno): %d:%d:%d\n", unos2->hour, unos2->minute, unos2->seconds);
 
    
    // Zbroj
    Time* zbroj = zbroji(unos1, unos2);

    printf("Zbroj: %d:%d:%d\n", zbroj->hour, zbroj->minute, zbroj->seconds);

    free(unos1);
    free(unos2);
    free(zbroj);

    return;
}

void zadatak2(){
    printf("\n===ZADATAK 2.===\n");

    flushInputBuff();
    Date* datum = getDate();

    printf("Datum unesen: %d.%d.%d\n", datum->day, datum->month, datum->year);
    printDateBeforeAndAfter(datum);

    free(datum);

    return;
}
void zadatak3(){
    printf("\n===ZADATAK 3.===\n");

    Person* osobe = malloc(PEOPLE_NUM * sizeof(Person));
    if(!osobe){
        printf("Neuspjena alokacija za niz osobe\n");
        return;
    }

    getPeopleData(osobe, PEOPLE_NUM);

    printAllPeople(osobe, PEOPLE_NUM);

    printf("\nInformacije o najstarijoj osobi:");
    printPerson(findAndPrintOldestPerson(osobe, 5));

    printf("\nInformacije o osobi prvoj po abecedi: ");
    printPerson(findAndPrintAlphaFirstPerson(osobe, 5));

    return;
}