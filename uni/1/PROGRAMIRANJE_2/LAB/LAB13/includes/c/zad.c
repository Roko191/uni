#include <stdio.h>
#include <stdlib.h>

#include "../func.h"

void zadatak1(){
    printf("\n=== ZADATAK 1. ===\n");
    int elNum = getArraySize();
    int target = getTagetNumber();
    int *arr;

    if(getArray(elNum, &arr)){
        printf("ERR\n");
        return;
    }
    
    if(findNumInArray(arr, target, elNum)){
        printf("Broj %d pronaden u nizu!\n", target);
    } else {printf("Broj %d nije pronaden u nizu!\n", target);}

    free(arr);
    return;
}

void zadatak2(){
    printf("\n=== ZADATAK 2. ===\n");
    int num = getNumber();
    int dCnt;
    char* numStr = formatNumToString(num, &dCnt);
    printString(numStr, dCnt);

    free(numStr);

    return;
}

void zadatak3(){
    printf("\n=== ZADATAK 3. === \n");
    printf("O koliko studneata zelis podatke: ");
    
    FILE* studentFile = fopen("students.txt", "r");
    if(!studentFile){
        printf("Fajl neuspojeno otvoren. Vjv nije pronaden");
        return;
    }
    
    int studenstNum;
    Student** students;
    scanf("%d", &studenstNum);

    if(getStudentDataFromFile(&students, studentFile, studenstNum) == NOT_ENOUGH_STUDENTS){
        printf("U fajlu nema dovoljno studenata tog broja! \n");
        return;
    }
    getPointsFromConsole(students, studenstNum);
    printStudentDataToConsole(students, studenstNum);

    for (int i = 0; i < studenstNum; i++) {
        free(students[i]); 
    }

    free(students);
    fclose(studentFile);
    return;
}

