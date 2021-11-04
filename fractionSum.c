#include <iostream>
using namespace std;

int main() {
    int n;
    int q, p, a, b;
    scanf("%d", &n);
    scanf("%d/%d", &q,&p);
    for(int i = 1; i < n; ++i) {
        scanf("%d/%d", &b,&a);
        // q/p += a/b
        // check denominator division
        if(p % a == 0) {
            int times = p/a;
            q += b * times;
        } else if(a % p == 0) {
            int times = a/p;
            q = q*times + b;
            p = a;
        } else {
            q = a*q + p*b;
            p = p*a;
        }
        printf("%d/%d\n", q, p);
    }
    int c = p, d = q;
    while(d != 0) {
        int r = d;
        d = c % d;
        c = r;
    }
    q /= c;
    p /= c;
    if(q % p != 0) {
        printf("%d/%d", q,p);
    } else {
        printf("%d", q/p);
    }
}
