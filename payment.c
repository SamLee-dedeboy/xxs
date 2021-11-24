#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int cash[6] = {100, 50, 20, 10, 5, 1};
    int num[6];
    for(int i = 0; i < 6; ++i) {
        num[i] = n/cash[i];
        n -= num[i] * cash[i];
    }
    for(int i = 0; i < 6; ++i) {
        printf("%d\n", num[i]);
    }
}

