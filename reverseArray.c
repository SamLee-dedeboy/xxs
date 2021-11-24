#include <stdio.h>
#include <math.h>

int main() {
    int n;

    scanf("%d", &n);
    int* list = malloc(n * sizeof(int));
    for(int i = 0; i < n; ++i) {
        scanf("%d", &list[i]);
    }
    for(int i = n - 1; i >=0; --i) {
        printf("%d ", list[i]);
    }
}

