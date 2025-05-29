#include <stdio.h>

#include "includes/zad.h"

int main(){
    printf("===LAB 11===\n");

    int zad;
    int loop = 1;

    while(loop){
        printf("Koji zadatak zelis porkenit: ");
        scanf(" %d", &zad);
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