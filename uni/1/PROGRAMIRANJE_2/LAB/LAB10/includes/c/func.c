#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../func.h"


Date* getDate(){
    printf("\tUnesi datum [DD.MM.YYYY]: ");
    
    Date* datum = malloc(sizeof(Date));

    // flushInputBuff();
    char* strDatum = createHeapString();

    sscanf(strDatum, "%d.%d.%d", &datum->day, &datum->month, &datum->year);
    free(strDatum);

    return datum;
}

Time* getTime(){
    Time* vrime = malloc(sizeof(Time)); 

    printf("\tUnesi uru rodenja [HH:MM:SS]: ");
    //   flushInputBuff();
    char* strUnos1 = createHeapString();

    int parsed = sscanf(strUnos1, "%d:%d:%d", &vrime->hour, &vrime->minute, &vrime->seconds);
    //printf("parsed = %d | Rezultat: %d:%d:%d\n", parsed, vrime->hour, vrime->minute, vrime->seconds);
    free(strUnos1);

    return vrime;
}

Time* zbroji(Time* vrime1, Time* vrime2){
    Time* zbroj = (Time*)malloc(sizeof(Time));

    zbroj->hour = vrime1->hour + vrime2->hour;
    zbroj->minute = vrime1->minute + vrime2->minute;
    zbroj->seconds = vrime1->seconds + vrime2->seconds;

    if(zbroj->seconds >= 60){
        zbroj-> minute += (zbroj->seconds / 60);
        zbroj->seconds %= 60;
    }

    if(zbroj->minute >= 60){
        zbroj-> hour += (zbroj->minute / 60);
        zbroj->minute %= 60; 
    }
    
 
    return zbroj;
}


int checkLeapYear(int godina){
    if (godina % 400 == 0)
        return 1;
    
    else if (godina % 100 == 0)
        return 0;

    else if (godina % 4 == 0)
        return 1;

    return 0;
}

Date* calculateDateAfter(Date* datum){
    Date* resDate = malloc(sizeof(Date));

    resDate->day = datum -> day;
    resDate->month = datum -> month;
    resDate->year = datum -> year;


    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    
    if(checkLeapYear(resDate->year)){
        months[1] = 27;
    }

    if(resDate -> day < 1){
        resDate -> day = 1; 
    } else if(resDate -> day  > months[resDate -> month - 1]) {
        resDate -> day = months[resDate -> month -1];
    }
    else if((resDate -> day == 31 && resDate -> month == 12)){
        resDate -> day = 1;
        resDate -> month = 1;
        resDate -> year += 1;
    }
    else if(months[resDate->month - 1] <= resDate -> day){
        resDate -> day = 1;
        resDate -> month += 1;        
    }
    else{
        resDate->day = resDate->day + 1;
    }

    return resDate;
}


Date* calculateDateBefore(Date* datum){
    Date* resDate = malloc(sizeof(Date));

    resDate->day = datum -> day;
    resDate->month = datum -> month;
    resDate->year = datum -> year;


    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(checkLeapYear(resDate->year)){
        months[1] = 27;
    }

    if(resDate -> day ==  1 && resDate -> month == 1){
        resDate -> day = 31;
        resDate -> month = 12;
        resDate -> year -= 1;
    }
    else if(resDate -> day == 1){
        resDate -> day = months[(resDate -> month - 1) - 1];
        resDate -> month -= 1;
    } else {
        resDate -> day -= 1;
    }


    return resDate;
}

void printDateBeforeAndAfter(Date* datum){
    Date* dateAfter = calculateDateAfter(datum);
    Date* dateBefore = calculateDateBefore(datum);
    
    
    printf("Datum prije: %d.%d.%d\n", dateBefore -> day, dateBefore -> month, dateBefore -> year);    
    printf("Datum poslije: %d.%d.%d\n", dateAfter -> day, dateAfter -> month, dateAfter -> year);

    return;
}


int getPeopleData(Person *osoba, int arrSize){
    if(!osoba){
        return -1;
    }

    flushInputBuff();

    for(int i = 0; i < arrSize; i++){
        printf("Upisi podateke o %d. osobi:\n", i + 1);
        printf("\tIme i prezime[IME PREZIME]: ");
        char* ime = createHeapString();

        if(!ime){
            return -1;
        }

        char* spacePtr = strchr(ime , ' ');

        if(!spacePtr){
            printf("Nepravilan unos . Pokusaj ponovno \n");
            free(ime);
            i--;
            continue;
        }

        size_t nameLen = spacePtr - ime;
        size_t surnameLen = strlen(spacePtr + 1);

        osoba[i].name = malloc(nameLen + 1);
        osoba[i].surname = malloc(surnameLen + 1);

        if(!osoba[i].name || !osoba[i].surname){
            free(ime);
            return -1;
        }


        strncpy(osoba[i].name, ime, nameLen);
        osoba[i].name[nameLen] = '\0';
        strncpy(osoba[i].surname, spacePtr + 1, surnameLen);
        osoba[i].surname[surnameLen] = '\0';

        free(ime);

        Date* tmpBirthday = getDate();
        Time* tmpBirthTime = getTime();

        osoba[i].birthday = malloc(sizeof(Date));
        osoba[i].birthday -> day = tmpBirthday -> day;
        osoba[i].birthday -> month = tmpBirthday -> month;
        osoba[i].birthday -> year = tmpBirthday -> year;
        free(tmpBirthday);

        osoba[i].birthtime = malloc(sizeof(Time));
        osoba[i].birthtime -> hour = tmpBirthTime -> hour;
        osoba[i].birthtime -> minute = tmpBirthTime -> minute;
        osoba[i].birthtime -> seconds = tmpBirthTime -> seconds;
        free(tmpBirthTime);
    }
    return 0;
}

void printPerson(Person* osoba){
    printf("\nIme i prezime: %s %s\n", osoba->name, osoba->surname);
    printf("Datum rodenja: %d.%d.%d\n", osoba->birthday -> day, osoba->birthday -> month, osoba->birthday -> year);
    printf("Sat rodenja: %d:%d:%d\n", osoba->birthtime -> hour, osoba->birthtime -> minute, osoba->birthtime -> seconds);    
}

void printAllPeople(Person* osoba, int arrSize){
    for(int i = 0; i < arrSize; i++){
        printf("\nPodaci o osobi %d\n", i + 1);
        printPerson(&osoba[i]);

    }
}

int compareDates(Date *a, Date *b){
   if( a->year != b->year ) return ( a->year < b->year ) ? -1 : 1;
   if( a->month != b->month ) return ( a->month < b->month ) ? -1: 1;
   if ( a->day != b->day ) return (a -> day < b -> day) ? -1 : 1;
   
   return 0;
}

int compareTimes(Time *a, Time *b){
    if ( a->hour != b->hour ) return ( a->hour < b->hour ) ? -1 : 1;
    if ( a->minute != b->minute ) return ( a->minute < b->minute ) ? -1 : 1;
    if ( a->seconds != b->seconds ) return ( a->seconds < b->seconds ) ? -1 : 1;
 
    return 0;
}

Person* findAndPrintOldestPerson(Person* osobe, int arrSize) {
    if (!osobe || arrSize <= 0) return NULL;

    Person* oldest = &osobe[0];

    for (int i = 1; i < arrSize; i++) {
        int birthday = compareDates(osobe[i].birthday, oldest->birthday);

        if (birthday < 0) {
            oldest = &osobe[i];
        } else if (birthday == 0) {
            int birthtime = compareTimes(osobe[i].birthtime, oldest->birthtime);
            if (birthtime < 0) {
                oldest = &osobe[i];
            }
        }
    }

    return oldest;
}


Person* findAndPrintAlphaFirstPerson(Person* osoba, int arrSize){
    if (!osoba || arrSize <= 0) return NULL;

    Person* alpha = &osoba[0];

    for (int i = 1; i < arrSize; i++) {
        int nameCmp = strcmp(osoba[i].name, alpha->name);

        if (nameCmp < 0) {
            alpha = &osoba[i];
        } else if (nameCmp == 0) {
            if (strcmp(osoba[i].surname, alpha->surname) < 0) {
                alpha = &osoba[i];
            }
        }
    }

    return alpha;
}