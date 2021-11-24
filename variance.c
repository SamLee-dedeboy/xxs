#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int *data = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }
    double mean = 0, variance = 0;
    for(int i = 0; i < n; ++i) {
        mean += data[i];
    }
    mean /= n;
    for(int i = 0; i < n; ++i) {
        variance += (data[i] - mean) * (data[i] - mean);
    }
    variance /= n;
    printf("%.5f %.5f", mean, variance);

    
}

