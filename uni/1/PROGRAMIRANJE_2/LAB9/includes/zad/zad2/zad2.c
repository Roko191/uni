#include <stdio.h>

#include "zad2.h"


#define MATRIX_SIZE 3

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

void zadatak2(){
    printf("\nZADATAK 2\n");

    int total = 1;

    int matra[3][3];

    printf("Unos 3x3 matrice: \n");
    zd2_unos((int*)matra);

    int res = zd2_mnozenje((int *)matra, 0, 1);

    printf("Umnozak svih elemenata matrice je %d", res);

    printf("\n");
}