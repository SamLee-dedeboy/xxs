#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int a) {
    if(a == 2) {
        return true;
    }
    for(int i = 2; i < sqrt(a)+1; ++i) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int m;
    scanf("%d", &m);
    int tmp = m;
    int i = 2;
    int previous = 0;
    while(!isPrime(tmp)) {
        if(isPrime(i)) {
            if(tmp % i == 0) {
                tmp /= i;
                if(previous != i) {
                    printf("%d\n", i);
                }
                previous = i;
                continue;
            }
        }
        ++i;
    }
    if(tmp != previous) 
        printf("%d\n", tmp);
}
