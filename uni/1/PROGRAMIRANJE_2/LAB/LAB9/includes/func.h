#pragma once

/* FUNKCIJE ZA ZAD 1. */

// Utility funckije
void zd1_unos(int *niz);
void zd1_ispis(int *niz);
int zd1_search(int *niz, int broj); // Ova mora bit rekurzivna


/* FUNKICJE ZA ZAD 2. */

int** createMatrix(int rows, int col);

void zd2_unos(int *matrica);
int zd2_mnozenje(int *matrica, int index, int total); // Mora bit rekurzivna???


/* FUNKCIJE ZA ZAD 3. */

char* createHeapString();

int myStrlen(char *string);
void myStrcpy(char *src, char *dst);

/* FUNKCIJE ZA ZAD 4. */
unsigned long long factoriel(unsigned int num);

/* FUNKICJE ZA ZAD 5. */
unsigned long long fibonaci(unsigned int num);

/* FUNKCIJE ZA ZAD 6. */
int findMin(int *niz, int arrSize, int start);
int findMax(int *niz, int arrSize, int start);