#include <stdlib.h>
#include <string.h>
#include "../func.h"


int getArraySize(){
    int num;
    printf("Unesi broj elemenata niza: ");
    scanf("%d", &num);
    return num;
}

int getArray(int elNum, int** array){
    int* arr = malloc(elNum * sizeof(int));
    if(!arr){
        return ERR_ALLOC_FAIL;
    }

    for(int i = 0; i < elNum; i++){
        int tmp;
        printf("Unesi broj: ");
        scanf("%d", &tmp);
        arr[i] = tmp;
    }

    *array = arr;

    return OK;
}
int getTagetNumber(){
    int num;
    printf("Unesi broj koji trazis u nizu: ");
    scanf("%d", &num);
    return num;
}

int findNumInArray(int* arr, int target, int arrSize){
    for(int i = 0; i < arrSize; i++){
        if(arr[i] == target){
            return 1;
        }
    }

    return OK;
}

int getNumber(){
    int num;
    printf("Unesi broj za pretvorbu: ");
    scanf("%d", &num);
    return num;
}

char* formatNumToString(int number, int* dCnt){
    int num = number;
    int digitCnt = 0;

    while(num / 10){
        digitCnt++;
        num /= 10;
    }
    digitCnt++;

    char* numString = malloc(digitCnt * sizeof(char));
    sprintf(numString, "%d", number);

    *dCnt = digitCnt;

    return numString;
}

int printString(char* string, int digitCnt){
    if(!string){
        return ERR_FUNC_ARG_BAD;
    }

    for(int i = 0; i < digitCnt; i++){
        printf("%c\n", string[i]);
    }
    
    return OK;
}

int getStudentDataFromFile(Student*** students, FILE* stream, int studnetNum){
    if(!stream || !students){
        return ERR_FUNC_ARG_BAD;
    }

    int pCnt = 0;
    int size = 1;

    Student** tmpPersons = malloc(size * sizeof(Student*));
    if(!tmpPersons){
        return ERR_ALLOC_FAIL;
    }

    size_t sizeLine = 0;
    char *line = NULL;

    while(getline(&line, &sizeLine, stream) != -1){
        if(pCnt  == studnetNum){
            break;
        }
        
        Student* tmpPerson = malloc(sizeof(Student));
        if(!tmpPerson){
            return ERR_ALLOC_FAIL;
        }

        char *name;
        char *surname;

        name = strtok(line, " ");
        surname = strtok(NULL, "\n");

        tmpPerson -> name = strdup(name);
        tmpPerson -> surname = strdup(surname);
        tmpPerson -> first_sem = 0;
        tmpPerson -> sec_sem = 0;

        if(size - 1 <= pCnt){
            size += 1;
            Student** tmp = realloc(tmpPersons, size * sizeof(Student*));
            if(!tmp){
                return ERR_ALLOC_FAIL;
            }
            tmpPersons = tmp;
        }

        tmpPersons[pCnt++] = tmpPerson;

        //size_t nameLen = spacePtr - line;
        //size_t surnameLen = strlen(spacePtr + 1);
    }


    if(pCnt < studnetNum) {
        return NOT_ENOUGH_STUDENTS;
    }

    *students = tmpPersons;

    free(line);
    return OK;
    
}

int getPointsFromConsole(Student** students, int studentNum){
    if(!students){
        return ERR_FUNC_ARG_BAD;
    }
    
    for(int i = 0; i < studentNum; i++){
        int first;
        int sec;
        while(1){
            printf("\nUnesi bodove za prvi kolokvij (%s %s): ", students[i] -> name, students[i] -> surname);
            scanf("%d", &first);

            if(first < 0 || first > 50){
                printf("Pokusaj ponovno (0 - 50)");
                continue;
            }

            break;

        }

        while(1){
            printf("Unesi bodove za drugi kolokvij (%s %s): ", students[i] -> name, students[i] -> surname);
            scanf("%d", &sec);

            if(sec < 0 || sec > 50){
                printf("Pokusaj ponovno (0 - 50)\n");
                continue;
            }

            break;

        }

        students[i] -> first_sem = first;
        students[i] -> sec_sem =  sec;

    }

    return OK;
}

int getGrade(Student* student){
    if(student -> first_sem < 25 || student -> sec_sem < 25){
        return 1;
    }

    int bodovi = student -> first_sem + student -> sec_sem;


    if(bodovi < 0){
        return 0;
    } else if (bodovi < 50) {
        return 1;
    } else if (bodovi < 60) {
        return 2;
    } else if(bodovi < 75){
        return 3;
    } else if(bodovi < 88){
        return 4;
    } else if (bodovi <= 100) {
        return 5;
    }

    return 0;

}

int printStudentDataToConsole(Student** students, int studentNum){
    if(!students){
        return ERR_FUNC_ARG_BAD;
    }

    for(int i = 0; i < studentNum; i++){
        printf("\n-- Informacije o %d studnetu ---\n", i + 1);
        printf("Ime i Prezime: %s %s\n", students[i] -> name, students[i] -> surname);
        printf("Bodovi: %d (%d %d)\n", students[i] -> first_sem + students[i] -> sec_sem, 
        students[i] -> first_sem, students[i] -> sec_sem);
        printf("Ocjena: %d\n", getGrade(students[i]));
    }

    return OK;
}