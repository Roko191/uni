#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../func.h"
#include "../zad.h"


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

void zadatak2(){
    printf("\nZADATAK 2\n");

    int total = 1;

    int** matra = createMatrix(3, 3);

    if(!matra){
        printf("Inicijilizacija matrice neuspojesna");
        return;
    }

    printf("Unos 3x3 matrice: \n");
    zd2_unos((int*)matra);

    int res = zd2_mnozenje((int *)matra, 0, 1);

    printf("Umnozak svih elemenata matrice je %d", res);

    printf("\n");

    free(matra);
}

void zadatak3(){
    // očisti stdin ako je nešto ostalo u njemu
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Unesi string: ");
    char *tekst = createHeapString();

    if(tekst == NULL){
        printf("*tekst: NULL POINTER");

        return;
    }

    char *kopiraniTekst = malloc(strlen(tekst) + 1);
    char *stdKopiraniTekst = malloc(strlen(tekst) + 1);

    if(kopiraniTekst == NULL || stdKopiraniTekst == NULL){
        printf("kopiraniTekst ili stdKopirani tekst nisu alocirani");
        return;
    }

    printf("\nZADATAK 3.\n");

    printf("Uneseni string: %s\n", tekst);

    printf("myStrlen(): %d\n", myStrlen(tekst));
    printf("strlen(): %lu\n", strlen(tekst));
    
    myStrcpy(tekst, kopiraniTekst);
    printf("myStrcpy(): %s\n", kopiraniTekst);
    strcpy(stdKopiraniTekst, tekst);
    printf("strcpy(): %s", stdKopiraniTekst);

    printf("\n");
    free(tekst);
    free(kopiraniTekst);
    free(stdKopiraniTekst);
}

void zadatak4(){
    printf("\nZADATAK 4.\n");
    printf("Koji faktorijel zelis izracnat: ");

    unsigned int n;
    scanf("%u", &n);

    printf("Faktorijel je %llu",factoriel(n));

    printf("\n");
}

void zadatak5(){
    printf("\nZADATAK 5.\n");
    printf("Upisi broj: ");

    int broj;
    scanf("%u", &broj);

    printf("Fibonacci niz: \n");
    for(unsigned int i = 0; i < broj; i++){
        printf("%llu ", fibonaci(i));
    }
 
    printf("\n");
    
    return;
}

void zadatak6(){
    printf("\nZADATAK 6.\n");
    int brojevi[] = {10, 11, 25, 467, 0, 12, 13, 16};

    printf("Najmani je %d\n", findMin(brojevi, 8, 0));
    printf("Najveci je %d\n", findMax(brojevi, 8, 0));

    return;
}