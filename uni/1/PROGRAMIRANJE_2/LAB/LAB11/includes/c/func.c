#include <stdio.h>
#include <stdlib.h>

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

    rez -> multiply = data -> a * data -> b;
    rez -> division = (float)data -> a / data -> b;
    rez -> sum = data -> a + data -> b;
    rez -> diff = data-> a - data->b;

    return rez;
}