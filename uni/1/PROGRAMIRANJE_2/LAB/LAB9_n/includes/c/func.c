#include <stdio.h>

#include "../zad.h"

/* Funkicje za 1. zadatak */ 

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

/* Funkcije za 2. zadatak */

// Zamjenit s fillMatrix() is libLabUtils.so
void zd2_unos(int *matrica){
	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("Unesi %d. element: ", i * MATRIX_SIZE + j + 1);
			scanf("%d", matrica + i * MATRIX_SIZE + j); // Fenci igranje s pointerima da procitamo iznos na tocnom adresnom mjestu 
		}
		printf("\n");
	}   
}

int zd2_mnozenje(int *matrica, int index,int total){
    if(index == MATRIX_SIZE * MATRIX_SIZE)
        return total;

    return zd2_mnozenje(matrica, index + 1, total * (*(matrica + index)));
}


/*Funkcije za 3. zadatak */

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

/* Funkcije za 4. zadatak */

unsigned long long factoriel(unsigned int num){
    if(num == 1){
        return num;
    }

    return num * factoriel(num - 1);
    
}