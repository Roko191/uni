#include "zad3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ENTER '\n' // New line is enter in Linux

char* zd3_unos(){

    printf("Unesi string za zadatak: ");

    int size = 1;
    int index = 0;

    char ch = 0;

    char *sPoint = malloc(size);

    while(1){
        ch = getc(stdin);

        // printf("\n ch: %c", ch);

        if(ch == ENTER || ch == EOF){
            break;
        }

        if(size - 1 <= index){
            size += 1;

            char *temp;

            temp = (char *)realloc(sPoint, size);
            if(!temp){
                free(sPoint);
                return NULL;
            }

            sPoint = temp;
        }

        sPoint[index++] = ch;

    }
    
    sPoint[index] = '\0';

    return sPoint;

}


int myStrlen(char *string){
    static int count = 0;


    if(*(string + count) == '\0'){
        return count; 
    }

    count++;

    myStrlen(string);

    return count;
}

void myStrcpy(char *src, char *dst){
    *dst = *src;
    
    if (*src) myStrcpy(src + 1, dst + 1);

}

void zadatak3(){
    // očisti stdin ako je nešto ostalo u njemu
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char *tekst = zd3_unos();

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