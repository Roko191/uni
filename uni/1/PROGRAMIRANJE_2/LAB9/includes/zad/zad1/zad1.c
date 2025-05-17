#include <stdio.h>

#include "zad1.h"

#define NIZ_SIZE 10 // Fixed niz size; recusrsion limter

void zd1_unos(int *niz){
    for(int i = 0; i < NIZ_SIZE; i++){
        printf("Unesi %d. broj: ", i);
        scanf("%d", niz + i);
    }
}

void zd1_ispis(int *niz){
    printf("Niz: \n");
    for(int i = 0; i < NIZ_SIZE; i++){
        printf("%d ", *(niz + i));
    }
}

int zd1_search(int *niz, int broj){
    static int limiter = 0;

    if(limiter == NIZ_SIZE - 1){
        return 0;
    }

    limiter++;

    zd1_search(niz, broj);

    return 1;
}

void zadatak1(){
    printf("ZADATAK 1. \n");

    int niz[NIZ_SIZE];

    zd1_unos(niz);
    zd1_ispis(niz);

    printf("\nKoji broj u nizu trazis: ");
    int searchNum;
    scanf("%d", &searchNum);


    if(!zd1_search(niz, searchNum)){
        printf("Broj %d nije pronaden", searchNum);
    }
    else {
        printf("Broj %d pronaden!", searchNum);
    }



    printf("\n");
}