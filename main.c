#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//31 jours sur le mois de mars
//31 jours sur le mois d'octobre

unsigned int dayOfWeek(unsigned int y, unsigned int m, unsigned int d){
    unsigned int total;
    unsigned int yM;
    unsigned int vD;
    if (m < 3){
        yM = y - 1;
        vD = 4;
    }else{
        yM = y;
        vD = 2;
    }
    unsigned int xA = floor(23 * m / 9);
    unsigned int xB = floor(yM / 4);
    unsigned int xC = floor(yM / 100);
    unsigned int xD = floor(yM / 400);
    total = (xA + d + vD + y + xB - xC + xD) % 7;
    return total;
}

unsigned int summerTimeDayChange(unsigned int y){
    unsigned int weekDay = dayOfWeek(y, 3, 31);
    return 31 - weekDay;
}

unsigned int winterTimeDayChange(unsigned int y){
    unsigned int weekDay = dayOfWeek(y, 10, 31);
    return 31 - weekDay;
}

int main(int argc, char *argv[]){

    char * yearS = argv[1];

    unsigned int y = atoi(yearS);
    
    unsigned int winterDayClockChange = winterTimeDayChange(y);
    unsigned int summerDayClockChange = summerTimeDayChange(y);

    printf("Summer Time : In year %d, the %d of March at 2AM, it will be 3AM\n", y, summerDayClockChange);
    printf("Winter Time : In year %d, the %d of October at 3AM o'clock, it will be 2AM\n", y, winterDayClockChange);

    return 0;
}