#include <stdio.h>

// Includovi za zadatke
#include "includes/zad/zad1/zad1.h"
#include "includes/zad/zad2/zad2.h"
#include "includes/zad/zad3/zad3.h"
#include "includes/zad/zad4/zad4.h"
#include "includes/zad/zad5/zad5.h"
#include "includes/zad/zad6/zad6.h"


int main(){
    printf("===LAB 9===\n");

    int zad;
    int loop = 1;

    while(loop){
        printf("Koji zadatak zelis porkenit: ");
        scanf("%d", &zad);
        switch(zad){
            case 1:
                zadatak1();
                printf("===ZAD 1 - END===\n");
                break;
            case 2:
                zadatak2();
                printf("===ZAD 2 - END===\n");
                break;
            case 3:
                zadatak3();
                printf("===ZAD 3 - END===\n");
                break;
            case 4:
                zadatak4();
                printf("===ZAD 4 - END===\n");
                break;
            case 0:
                loop = 0;
                break;
            default:
                break;
        }
    }

    return 0;
}


