#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int *age = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &age[i]);
    }
    int bucket[4] = {0, 0, 0, 0};
    for(int i = 0; i < n; ++i) {
        if(age[i] <= 18) bucket[0]++;
        else if(age[i] <= 35) bucket[1]++;
        else if(age[i] <= 60) bucket[2]++;
        else bucket[3]++;
    }
    printf("1-18: %.2f%%\n", (double)100*bucket[0]/n);
    printf("19-35: %.2f%%\n", (double)100*bucket[1]/n);
    printf("36-60: %.2f%%\n", (double)100*bucket[2]/n);
    printf("Over60: %.2f%%\n", (double)100*bucket[3]/n);

    
}

