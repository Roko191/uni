#include <stdio.h>
#include <stdlib.h>

#include "../func.h"

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

    return resDate;
}

void printDateBeforeAndAfter(Date* datum){
    Date* dateBefore = calculateDateAfter(datum);
    
    printf("\nDatum poslije: %d.%d.%d\n", dateBefore -> day, dateBefore -> month, dateBefore -> year);    

    return;
}


