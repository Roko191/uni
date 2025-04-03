// #define _CRT_SECURE_NO_WARNINGS // Define if on windows (scanf() usage)

#include <stdio.h>

#define true 1
int main() {
	// 1. Zadatak
	printf("\nZADATAK 1.\n");
	int ocjene[20];

	int cnt = 0;

	// Unos ocjena
	while (true)
	{
		if (cnt > 19) {
			break;
		}

		int ocjena;
		printf("Unesi ocjenu: ");
		scanf("%d", &ocjena);

		if (ocjena < 1 || ocjena > 5) {
			printf("Unos mora biti izmedu 1 i 5 \n");
			continue;
		}
		else
		{
			printf("Ocjena unesena! \n");
			ocjene[cnt] = ocjena;
			cnt++;
		}

	}

	int jedan = 0, dva = 0, tri = 0, cetri = 0, pet = 0;

	for(int i = 0; i < 20; i++)
	{
		switch (ocjene[i]) {
			case 1:
				jedan++;
				break;
			case 2: 
				dva++;
				break;
			case 3:
				tri++;
				break;
			case 4:
				cetri++;
				break;
			case 5:
				pet++;
				break;
		}
	}


	printf("Ocjene:\n");
	printf("	Jedan: %d\n", jedan);
	printf("	Dva: %d\n", dva);
	printf("	Tri: %d\n", tri);
	printf("	Cetri: %d\n", cetri);
	printf("	Pet: %d\n", pet);
	printf("\n");

	// 2. zadatak
	printf("\nZADATAK 2.\n");
	int niz[10] = { 2, 1 , 4, 0, 564, 6, 67, 100, -20, 24};

	for (int i = 0; i < 10; i++) {
		printf("Unesi %d element niza: ", i);
		scanf("%d", &niz[i]);
	}

	// Najmanji
	int lowestIndex = 0;
	for(int i = 0; i < 10; i++)
	{
		if(niz[i] < niz[lowestIndex])
		{
			lowestIndex = i;
		}
	}

	printf("Najmanji broj u nizu je: %d\n", niz[lowestIndex]);

	// Najveci
	int bigestIndex = 0;
	for (int i = 0; i < 10; i++)
	{
		if (niz[i] > niz[bigestIndex])
		{
			bigestIndex = i;
		}
	}
	printf("Najveci broj u nizu je: %d\n", niz[bigestIndex]);
	

	// Bubble sort niz
	for(int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if(niz[j] > niz[j + 1])
			{
				niz[j] = niz[j] + niz[j + 1];
				niz[j + 1] = niz[j] - niz[j + 1];
				niz[j] = niz[j] - niz[j + 1];
			}
		}
	}

	printf("Novi raspored varijable niz je: \n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", niz[i]);
	}

	printf("\n");

	// Zadatak 3.
	printf("\nZADATAK 3.\n");
	int brojevi[10];
	for (int i = 0; i < 10; i++) {
		printf("Unesi broj: \n");
		scanf("%d", &brojevi[i]);
	}
	
	int unos;
	printf("\nUpisi broj za provjeru: \n");
	scanf("%d", &unos);

	int count = 0;

	for (int i = 0; i < 10; i++) {
		if (brojevi[i] == unos) {
			count++;
		}
	}

	printf("Broj %d se pojavljuje u nizu %d puta", unos, count);
	printf("\n");

	return 0;
}