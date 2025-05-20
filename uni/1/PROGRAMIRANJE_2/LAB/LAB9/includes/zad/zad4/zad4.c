#include <stdio.h>


unsigned long long factoriel(unsigned int num){
    if(num == 1){
        return num;
    }

    return num * factoriel(num - 1);
    
}

void zadatak4(){
    printf("\nZADATAK 4.\n");
    printf("Koji faktorijel zelis izracnat: ");

    unsigned int n;
    scanf("%u", &n);

    printf("Faktorijel je %llu",factoriel(n));

    printf("\n");
}

