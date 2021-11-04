#include <iostream>
#include <math.h>
using namespace std;


int main() {
    int width, height;
    char c;
    int solid;
    while(true) {
        scanf("%d %d %c %d", &width, &height, &c, &solid);
        if(width == 0) {
            break;
        }
        for(int i = 0; i < width; ++i) {
            for(int j = 0; j < height; ++j) {
                if(j != 0 && j != height-1 && i != 0 && i != width - 1 && !solid) {
                    printf(" ");
                    continue;
                }
                printf("%c", c);
            }
            printf("\n");
        }
    
    }
    
}
