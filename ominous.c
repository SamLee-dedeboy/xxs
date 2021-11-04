#include <iostream>
#include <math.h>
using namespace std;


int main() {
    int w;
    int monthDaysTable[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    scanf("%d", &w);
    int total_days = 12;
    for(int i = 0; i < 12; ++i) {
        if((total_days % 7 + w) % 7 == 5) {
            printf("%d\n", i+1);
        }
        total_days += monthDaysTable[i];
    }
}
