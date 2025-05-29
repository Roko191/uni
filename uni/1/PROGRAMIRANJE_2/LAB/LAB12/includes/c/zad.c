#include <stdio.h>
#include <stdlib.h>
#include "../zad.h"
#include "../func.h"


void zadatak1(){
    printf("\n=== ZADATAK 1. ===\n");
    flushInputBuff();

    char* file1;
    char* file2;

    FILE* fp1;
    FILE* fp2;

    while(1){
        printf("Unesi ime 1. datoteke: ");
        
        file1 = createHeapString();

        fp1 = fopen(file1, "r");

        if(fp1 == NULL){
            printf("Datoteke 1. nije otvorena! \n Pogresno ime??? \n");
            continue;
        }

        printf("Unesi ime 2. datoteke: ");
        
        file2 = createHeapString();

        fp2 = fopen(file2, "w");

        if(fp2 == NULL){
            printf("Datoteke 2. nije otvorena! \n Pogresno ime??? \n");
            continue;
        }

        break;
    }
    

    copyFileContent(fp1, fp2);

    free(file1);
    free(file2);

    fclose(fp1);
    fclose(fp2);

    return;
}

void zadatak2(){
    printf("\n=== ZADATAK 2. ===\n");
    FILE* fajl;

    flushInputBuff();
    int res = getFile(&fajl, "r");
    
    if(res != 0){
        printf("%d\n", res);
        errPrint(res);
        return;
    }

    if(!fajl){
        printf("fajl NULL pointer???");
        return;
    }

    res = printParsedNumber(fajl);
    if(res){
        errPrint(res);
    }

    fclose(fajl);
    return;
}

void zadatak3(){
    printf("\n=== ZADATAK 3. ===\n");
    FILE* fajl;
    flushInputBuff();
    int res = getFile(&fajl, "r");
    if(res){
        errPrint(res);
        return;
    }
    if(!fajl){
        printf("fajl NULL???\n");
        return;
    }

    Person** osobe;
    int pCnt;
    readDataFromFile(fajl, &osobe, &pCnt);

    // printf("%s %s\n", osobe[1] -> name, osobe[339] -> surname);
    int count;
    printf("Unesi ime: ");
    char* name = createHeapString();
    countPeopleWithFirstName(osobe, name, pCnt, &count);
    printf("Osoba s imenom %s je pronadeno %d\n", name, count);

    for (int i = 0; i < pCnt; i++) {
        free(osobe[i]); 
    }

    free(osobe);
    fclose(fajl);
    return;
}

void zadatak4(){
    printf("\n=== ZADATAK 4. ===\n");
    FILE* fajl;
    flushInputBuff();
    int res = getFile(&fajl, "r");
    if(res){
        errPrint(res);
        return;
    }
    if(!fajl){
        printf("fajl NULL???\n");
        return;
    }


    printLineByLineWordByWord(fajl);

    fclose(fajl);

    return;
}