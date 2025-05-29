#include <stdio.h>
#include <stdlib.h>

#include "../func.h"
#include "../zad.h"

void zadatak1(){
    printf("\n=== ZADATAK 1. ===\n");

    int *intArr = createAndFillArray(ZD1_ARR_LEN);
    printf("Uneseni brojevi: \n");
    printArray(intArr, ZD1_ARR_LEN);

    char* charArr = createAndFillCharArray(ZD1_ARR_LEN);
    printCharArray(charArr, ZD1_ARR_LEN);

    printf("\n");

    free(intArr);
    free(charArr);

    return;
}

void zadatak2(){
    printf("\n=== ZADATAK 2. ===\n");

    Nums* brojevi = getData();
    if(!brojevi){
        return;
    }

    Results* rez = calcMathResults(brojevi);    

    printf("Rez mnozenja: %d\n", rez -> multiply);
    printf("Rez djeljenja: %f\n", rez -> division);
    printf("Rez zbrajanja: %d\n", rez -> sum);
    printf("Rez oduzimanja: %d\n", rez -> diff);


    free(brojevi);
    free(rez);

    return;
}

void zadatak3(){
    printf("\n=== ZADATAK 3. ===\n");

    flushInputBuff();
    Date* datum = getDate();

    if(!datum){
        return;
    }

    printDateBeforeAndAfter(datum);


    free(datum);
    return;
}

void zadatak4(){
    printf("\n=== ZADATAK 4. ===\n");

    flushInputBuff();

    char *str;
    char *sub;

    getString(&str);
    getSubString(&sub);

    int num = countSubstrOccurrences(str, sub);

    printf("Pronadeno %d sub stringova \n", num);

    free(str);
    free(sub);
    return;
}