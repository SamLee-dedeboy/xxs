#include <iostream>
using namespace std;

int main() {
    int n;
    int monthDaysTable[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    while(true) {
        scanf("%d", &n);
        if(n == -1) {
            break;
        }
        char* dayOfWeek = new char[10];
        switch (n%7) {
            case 0:
                dayOfWeek = (char*)"Saturday";
                break;
            case 1:
                dayOfWeek = (char*)"Sunday";
                break;
            case 2:
                dayOfWeek = (char*)"Monday";
                break;
            case 3:
                dayOfWeek = (char*)"Tuesday";
                break;
            case 4:
                dayOfWeek = (char*)"Wednesday";
                break;
            case 5:
                dayOfWeek = (char*)"Thursday";
                break;
            case 6:
                dayOfWeek = (char*)"Friday";
                break;
            default:
                dayOfWeek = (char*) "Null";
                break;
        }
        int year = 2000, month = 1, day = 1;
        while(n != 0) {
            monthDaysTable[1] = 28;
            if((year%4 == 0 && year%100 != 0) || year %400 == 0) {
                monthDaysTable[1] += 1;
            }            
            day++;
            if(day > monthDaysTable[month-1]) {
                day = 1;
                month ++;
                if(month > 12) {
                    year++;
                    month = 1;
                }
            }
            n--;
        }
        printf("%d-%d-%d %s\n", year, month, day, dayOfWeek);

    }
}
