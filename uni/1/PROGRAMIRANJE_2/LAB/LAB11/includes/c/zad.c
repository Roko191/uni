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

    return;
}

void zadatak3(){
    return;
}