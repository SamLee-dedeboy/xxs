#include <iostream>
using namespace std;

int main() {
    int n;
    int year, m1, m2;
    int monthDaysTable[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        monthDaysTable[1] = 28;
        scanf("%d %d %d", &year, &m1, &m2);
        if((year%4 == 0 && year%100 != 0) || year %400 == 0) {
            monthDaysTable[1] += 1;
        }

        int days = 0;
        if(m1 > m2) {
            int tmp = m1;
            m1 = m2;
            m2 = tmp;
        }
        for(int j = m1-1; j < m2-1; j++) {
            days += monthDaysTable[j];
        }
        //printf("%d %d: %d\n", m1, m2, days);
        if(days%7 == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
       

    }
   
}
