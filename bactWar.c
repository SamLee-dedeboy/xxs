#include <iostream>
#include <math.h>
using namespace std;


int main() {
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int good, bad;
        scanf("%d %d", &bad, &good);
        int t = 0;
        while(bad > 0) {
            bad -= good;

            bad *= 2;
            good *= 1.05;

            if(bad > 1000000) {
                bad = 1000000;
            }
            t++;   
        }
        printf("%d\n", t);
    }
}
