#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {

    srand((unsigned long)time(0));
    int arr[10];

    printf("Twoja poczatkowa tablica: ");
    for (int i = 0; i<10; i++) {
        arr[i] = rand()%30;
        printf("%d ", arr[i]);
    }

    int k;
    printf("\nPodaj indeks od ktorego chcesz zaczac wypisywanie z zakresu <0,9>: ");
    scanf("%d", &k);

    int wybor;
    printf("Podaj liczbe czy chcesz aby wypisywanie bylo do przodu (0) czy do tylu (1): ");
    scanf("%d", &wybor);

    if (wybor == 0){
        printf("\nTwoja tablica wypisywana od podanego indeksu k do przodu:\n");
        for (int i = k; i<10; i++) {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i<k; i++) {
            printf("%d ", arr[i]);
        }
    }

    else{
        printf("\nTwoja tablica wypisywana od podanego indeksu k do tylu:\n");
        for (int i = k; i>=0; i--) {
            printf("%d ", arr[i]);
        }
        for (int i = 10-1; i>k; i--) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
