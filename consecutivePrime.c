#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int a) {
    for(int i = 2; i < sqrt(a)+1; ++i) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int m,k;
    scanf("%d %d", &m, &k);
    for(int i = 0; i < k; ++i) {
        int j = m + 1;
        while(!isPrime(j)) {
            j++;
        }
        m = j;
        printf("%d", j);
        if(i != k-1) {
            printf(" ");
        }
    }
}
