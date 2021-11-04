#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < (n+1)/2; ++i) {
        int dist = (n+1)/2 - (i+1);
        int flower_num = n-2*dist;
        printf("$");
        for(int j = 0; j < (n-flower_num)/2; ++j) {
            printf(" ");
        }
        for(int j = 0; j < flower_num; ++j) {
            printf("*");
        }
        printf("\n");
    }
   for(int i = (n-1)/2 - 1; i >= 0; --i) {
        int dist = (n+1)/2 - (i+1);
        int flower_num = n-2*dist;
        printf("$");

        for(int j = 0; j < (n-flower_num)/2; ++j) {
            printf(" ");
        }
        for(int j = 0; j < flower_num; ++j) {
            printf("*");
        }
        printf("\n");
   }
}
