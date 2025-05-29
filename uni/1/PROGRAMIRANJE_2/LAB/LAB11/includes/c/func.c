#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../func.h"

char* createAndFillCharArray(int elCnt){
    char *res = malloc(10 * sizeof(char));

    if(!res){
        return NULL;
    }

    for(int i = 0; i < elCnt; i++){
        char tmp;

        printf("Unesi znak: ");
        flushInputBuff();
        *(res + i) = getchar();

    }

    return res;
}


int printCharArray(char *charArr, int elCnt){
    if(!charArr || elCnt < 0){
        return ERR_FUNC_ARG_BAD;
    }

    printf("Uneseni znakovi: \n");

    for(int i = 0; i < elCnt; i++){
        printf("%c ", *(charArr + i));
    }

    return OK;
}

Nums* getData(){
    Nums* brojevi = malloc(sizeof(Nums));

    if(!brojevi){
        return NULL;
    }
    
    printf("Unesi brojeve: ");
    scanf("%d %d", &(brojevi->a), &(brojevi->b));


    return brojevi;
}

Results* calcMathResults(Nums* data){
    if(!data){
        return NULL;
    }

    Results* rez = malloc(sizeof(Results));

    if(!rez){
        return NULL;
    }

    rez -> multiply = data->a * data->b;
    rez -> division = (float)data->a / data->b;
    rez -> sum = data->a + data->b;
    rez -> diff = data->a - data->b;

    return rez;
}


int checkLeapYear(int godina){
    if (godina % 400 == 0)
        return 1;
    
    else if (godina % 100 == 0)
        return 0;

    else if (godina % 4 == 0)
        return 1;

    return 0;
}

Date* getDate(){
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    Date* datum = malloc(sizeof(Date));

    while(1){
        printf("\tUnesi datum [DD.MM.YYYY]: ");

        char* strDatum = createHeapString();

        sscanf(strDatum, "%d.%d.%d", &datum->day, &datum->month, &datum->year);

        if(checkLeapYear(datum->year)){
            months[1] = 29;
        }


        if(datum -> day > months[datum ->  month - 1]
        || datum -> day < 1){
            printf("\tPogresan unos!\n");
            free(strDatum);
            continue;
        } else if(datum -> month < 1 || datum -> month > 12){
            printf("\tPogresan unos!\n");
            free(strDatum);
            continue;
        } else if (datum -> year < 1){
            printf("\tPogresan unos!\n");
            free(strDatum);
            continue;
        }

        free(strDatum);
        break;
    }
    // flushInputBuff();

    return datum;
}

void calculateDateAfter(Date* datum, Date** res){
    Date* resDate = malloc(sizeof(Date));

    if(!resDate){
        return;
    }

    resDate->day = datum -> day;
    resDate->month = datum -> month;
    resDate->year = datum -> year;


    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    
    if(checkLeapYear(resDate->year)){
        months[1] = 29;
    }

    if(resDate -> day < 1){
        resDate -> day = 1; 
    } else if(resDate -> day  > months[resDate -> month - 1]) {
        resDate -> day = months[resDate -> month -1];
    }
    else if((resDate -> day == 31 && resDate -> month == 12)){
        resDate -> day = 1;
        resDate -> month = 1;
        resDate -> year += 1;
    }
    else if(months[resDate->month - 1] <= resDate -> day){
        resDate -> day = 1;
        resDate -> month += 1;        
    }
    else{
        resDate->day = resDate->day + 1;
    }

    *res = resDate;

    return;
}


void calculateDateBefore(Date* datum, Date** res){
    Date* resDate = malloc(sizeof(Date));

    if(!resDate){
        return;
    }

    resDate->day = datum -> day;
    resDate->month = datum -> month;
    resDate->year = datum -> year;


    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(checkLeapYear(resDate->year)){
        months[1] = 29;
    }

    if(resDate -> day ==  1 && resDate -> month == 1){
        resDate -> day = 31;
        resDate -> month = 12;
        resDate -> year -= 1;
    }
    else if(resDate -> day == 1){
        resDate -> day = months[(resDate -> month - 1) - 1];
        resDate -> month -= 1;
    } else {
        resDate -> day -= 1;
    }


    *res = resDate;

    return;
}

void printDateBeforeAndAfter(Date* datum){
    Date* dateAfter; 
    calculateDateAfter(datum, &dateAfter);
    Date* dateBefore;
    calculateDateBefore(datum, &dateBefore);
    

    if(!dateAfter || !dateBefore){
        printf("Some alloc went wrong!");
        return;
    }
    
    printf("Datum prije: %d.%d.%d\n", dateBefore -> day, dateBefore -> month, dateBefore -> year);    
    printf("Datum poslije: %d.%d.%d\n", dateAfter -> day, dateAfter -> month, dateAfter -> year);

    return;
}


void getString(char **str){
    printf("Unesi glavni string: ");
    *str = createHeapString();
    
    return;
}

void getSubString(char **str){
    printf("Unesi sub string: ");
    *str = createHeapString();

    return;
}

int countSubstrOccurrences(char *string, char *sub){
    int cnt = 0;

    int i = 0;
    int j = 0;

    int subLen = strlen(sub);
    if(subLen == 0) return 0;


    while(string[i] != '\0'){
        if(string[i] == sub[j]){
            j++;

            if(j == subLen){
                j = 0;
                cnt++;
            }
        } else {
            j = 0;
        }

        i++;
    }
       

    return cnt;
}