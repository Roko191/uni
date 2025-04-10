// #define _CRT_SECURE_NO_WARNINGS Uncomment on Windows

#define STR_NAME_SIZE 20

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
	Argumenti:
		int *matra -> pointer koi upucuje na adresu provog elementa matrice
		row -> koliko redova ima matrica
		col -> koliko stupaca ima matrica
*/
void ispisMatre(int *matra, int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", *(matra + i * col + j)); // Fenci igranje s pointerima da procitamo iznos na tocnom adresnom mjestu 
		}
		printf("\n");
	}
}

void korisnikovUnos(int* matra, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("Unesi element [%d][%d]: ", i, j);
			scanf("%d", matra + i * col + j); // Arhimetika i ideja ista kao i kod ispisa, samo nema potrebe za derefrence scanf() je 
		}
	}
}


int main() {
	// ZADATAK 1
	printf("ZADATAK 1.\n");
	int matra[3][3];

	korisnikovUnos((int*)matra, 3, 3);
	ispisMatre((int *)matra , 3, 3); // (int*)matra == &matra[0][0]

	printf("\n");

	// ZADATAK 2.
	printf("ZADATAK 2. \n");

	int zd2matra[3][3];

	korisnikovUnos((int*)zd2matra, 3, 3);

	int transMatra[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			transMatra[j][i] = zd2matra[i][j];
		}
	}

	ispisMatre((int*)zd2matra, 3, 3);
	printf("\n");
	ispisMatre((int*)transMatra, 3, 3);
	printf("\n");

	// ZADATAK 3.
	printf("ZADATAK 3.\n");

	int matraA[3][3];
	int matraB[3][3];

	printf("Unesi vrijednosti za matricu A: \n");
	korisnikovUnos((int*)matraA, 3, 3);
	printf("Unesi vrijednosti za matricu B: \n");
	korisnikovUnos((int*)matraB, 3, 3);


	printf("Unesene matrice: \n");
	ispisMatre((int*)matraA, 3, 3);
	printf("\n");
	ispisMatre((int*)matraB, 3, 3);


	// C = A + B
	int matraC[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matraC[i][j] = matraA[i][j] + matraB[i][j];
		}
	}

	printf("\nZbroj (C = A + B) je: \n");
	ispisMatre((int*)matraC, 3, 3);
	printf("\n");

	// D = A * B
	int matraD[3][3];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matraD[i][j] = 0;

			for (int k = 0; k < 3; k++) {
				matraD[i][j] += matraA[i][j] * matraB[i][j];
			}
		}
	}

	printf("Rezultat mnozenje (D = A * B) je:  \n");
	ispisMatre((int*)matraD, 3, 3);

	// ZADATAK 4.
	char imena[5][STR_NAME_SIZE];

	// User input
	for (int i = 0; i < 5; i++) {
		printf("Unesi ime: \n");
		scanf("%s", &imena[i]);
	}

	printf("Imena koja si unio su: \n");
	for (int i = 0; i < 5; i++) {
		printf("%d. %s\n", i, imena[i]);
	}

	// Provjera za koji je po abcedi prvi
	int lowIndex = 0;

	printf("\nIme koje je prvo po abecedi je: \n");
	for (int i = 0; i < 5; i++) {
		if (tolower(imena[lowIndex][0]) > tolower(imena[i][0])) {
			lowIndex = i;
		}
	}

	printf("%d. %s\n", lowIndex, imena[lowIndex]);

	// Provjera za koji je abcedi zadnji
	int highIndex = 0;

	printf("\nIme koje je zadnje po abecedi je: \n");
	for (int i = 0; i < 5; i++) {
		if (tolower(imena[highIndex][0]) < tolower(imena[i][0])) {
			highIndex = i;
		}
	}

	printf("%d. %s\n", highIndex, imena[highIndex]);

	// Poredaj ih abecedno (bubble sort samo usoporedivanj slova???)
	for (int i = 0; i < 4; i++) {
		char tempString[STR_NAME_SIZE];
		for (int j = 0; j < 4 - i; j++) {
			if (tolower(imena[j][0]) > tolower(imena[j + 1][0])) {
				// String swap lol
				strcpy(tempString, imena[j]);
				strcpy(imena[j], imena[j + 1]);
				strcpy(imena[j + 1], tempString);
			}
		}
	}

	printf("Imena poredana abecedno su: \n");
	for (int i = 0; i < 5; i++) {
		printf("%d. %s\n", i, imena[i]);
	}
}
