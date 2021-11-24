#include <stdio.h>
#include <math.h>

int main() {
    int n;

    scanf("%d", &n);
    int input;
    int positive = 0, negative = 0, sum = 0, maxAbs = 0, minAbs = 2147483647;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &input);
        if(input > 0) positive++;
        if(input < 0) negative++;
        sum += input;
        if(abs(input) > maxAbs) maxAbs = abs(input);
        if(abs(input) < minAbs) minAbs = abs(input);
    }
    printf("%d\n%d\n%d\n%d\n%d", positive, negative, sum, maxAbs, minAbs);
}

