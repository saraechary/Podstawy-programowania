#include <stdio.h>
#include <math.h>


int main (void) {
    int n;
    printf("Wprowadz wybrana liczbe aby sprawdzic czy jest iloczynem dwoch kolejnych liczb z ciagu Fibonacciego: ");
    scanf("%d", &n);

    int c = 0;
    int d = 1;

    int zmienna = 0; // false
    
    while (d<1000){
        int temp;
        temp = c+d;
        c=d;
        d=temp;

        if (n == c*d || n == 0) {
            zmienna = 1;
            break;
        }
    }
    if (zmienna == 1) {
        printf("Liczba %d jest iloczynem dwoch kolejnych elementow ciagu Fibonacciego.", n);

    }
    else {
        printf("Liczba %d nie jest iloczynem dwoch kolejnych elementow ciagu Fibonacciego.", n);

    }

    return 0;
}