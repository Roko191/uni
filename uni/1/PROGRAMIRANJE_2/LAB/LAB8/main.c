#include <math.h>
#include <stdio.h> 


#define True 1

// CUSTOM DEFINES
#define FOO_RUN 5

// Globalne 
int x = 100;

// Definicije funkicja za prvi zadatak
int zbroji(int a, int b, int c);
int pomnozi(int a, int b, int c);
float mjesano(int a, int b, int c); // x / y + z
float sqrtmjesano(int a, int b, int c); // x / y - z 


// Definicije funkcija za drugi zadatak
int foo(int local);

// Def 3 zad
double faktorijel(int broj);

double myExpo(int n, int precision){
    double returnVal = 1;

    for(int i = 1; i <= precision; i++){
        returnVal += (double)pow(n, i) / faktorijel(i);
    }

    return returnVal;  
};


// Funkcije za zadatke
void zadatak1(){
    // ZADATAK 1
    printf("ZADATAK 1.\n");
    int a, b, c;
    printf("Unesi broj a: \n");
    scanf("%d", &a);
    printf("Unesi broj a: \n");
    scanf("%d", &b);
    printf("Unesi broj a: \n");
    scanf("%d", &c);

    printf("zbroji(): %d\n", zbroji(a, b, c));
    printf("pomnozi(): %d\n", zbroji(a, b, c));
    printf("mjesano(): %f\n", mjesano(a, b, c));
    printf("sqrtmjesano(): %f\n", sqrtmjesano(a, b, c));
    printf("\n");

    printf("\n");
};

void zadatak2(){
    // ZADATAK 2
    printf("ZADATAK 2\n");
    int y = 10;
    int z = 0;

    for(int i = 0; i < FOO_RUN; i++){
        foo(y);
    }

    printf("\n");
};

void zadatak3(){
    printf("ZADATAK 3.\n");

    int num;

    printf("Unesi broj za faktorijel: ");
    scanf("%d", &num);

    int res = faktorijel(num);

    if(res < 0){
        printf("Unio si broj manji od 0\n");
    } else {
        printf("Fakotorijel %d je %d\n", num, res);
    }

    printf("\n");
};

void zadatak4(){
    printf("\nZADATAK 4. \n");
    printf("Unesi x: ");
    int x;
    scanf("%d", &x);

    printf("exp(): %lf \n", exp(x));
    printf("myExpo() 5 ponavljanja: %lf \n", myExpo(x, 5));
    printf("myExpo() 10 ponavljanja: %lf \n", myExpo(x, 10));
    printf("myExpo() 50 ponavljanja: %lf \n", myExpo(x, 50));

    printf("\n");
};

int main(){
    int loop = 1;

    while (loop){
        printf("Koji zadatak: ");
        int zad;
        scanf("%d", &zad);
        
        switch(zad){
            case 1:
                zadatak1();
                continue;
            case 2:
                zadatak2();
                continue;
            case 3:
                zadatak3();
                continue;
            case 4:
                zadatak4();
                continue;
            default:
                printf("Pogrsan unos! \n");
                loop = 0;
                break;
                
        }
    } 

    return 0;

}

int zbroji(int a, int b, int c){
    return a + b + c;
}

int pomnozi(int a, int b, int c){
    return a * b * c;
}

float mjesano(int a, int b, int c){
    if(b + c == 0){
        printf("\nNedozvoljeno djeljenje s nulom \n");
        return -1;
    }
    return (float)a / b + c;
}

float sqrtmjesano(int a, int b, int c){
    if(b * c == 0){
        printf("\nNedozvoljeno djeljenje s nulom \n");
    }

    if(((float)a / b * c) ==  0){
        printf("\nNedozvoljeno djeljenje s nulom \n");
    }

    return sqrt((float)a / b * c);
}

int foo(int local)
{
    printf("Globlana varijabla: %d\n", x);
    printf("Lokalna varijabla: %d\n", local);

    static int z = 0;
    z++;

    printf("Funkcija je pokrenuta %d puta \n", z);

    return z;
}

double faktorijel(int broj){
    if (broj < 0){
        return -1;
    }

    double result = 1;
    while(broj > 0){
        result *= broj;
        broj--;
    }

    return result;
}