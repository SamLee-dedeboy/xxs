#include <stdio.h>
#include <math.h>

int main() {
    int n;

    scanf("%d", &n);
    int* score = malloc(n * sizeof(int));
    int* credit = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &credit[i]);
    }
     for(int i = 0; i < n; ++i) {
        scanf("%d", &score[i]);
    }
    double sum = 0;
    for(int i = 0; i < n; ++i) {
        double point = 0;
        if(score[i] >= 90 && score[i] <= 100) point = 4.0;
        else if(score[i] >= 85 && score[i] <= 89) point = 3.7;
        else if(score[i] >= 82 && score[i] <= 84) point = 3.3;
        else if(score[i] >= 78 && score[i] <= 81) point = 3.0;
        else if(score[i] >= 75 && score[i] <= 77) point = 2.7;
        else if(score[i] >= 72 && score[i] <= 74) point = 2.3;
        else if(score[i] >= 68 && score[i] <= 71) point = 2.0;
        else if(score[i] >= 64 && score[i] <= 67) point = 1.5;
        else if(score[i] >= 60 && score[i] <= 63) point = 1.0;
        else point = 0;
        sum += point * credit[i];
    }
    printf("%.2f", sum);
}

