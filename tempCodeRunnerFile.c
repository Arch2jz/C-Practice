#include <stdio.h>
int main(){
    int x;
    printf("enter the number for the triangle: ");
    scanf("%d",&x);

    for (int i = 1; i <= x; i++){

        // print spaces
        for (int j = 1; j <= x - i; j++){
            printf("  ");
        }

        // print stars
        for (int k = 1; k <= i; k++){
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}