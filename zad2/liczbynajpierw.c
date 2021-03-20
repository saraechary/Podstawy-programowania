#include <stdio.h>
#include <math.h>


int main (void) {

    int n,bool, jednosci, liczba;
    int licznik = 0;

    printf("Podaj koniec przedzialu: ");
    scanf("%d", &n);

    printf ("Liczby pierwsze mniejsze od %d, ktorych cyfry tworza ciag niemalejacy: \n", n);

    for(int i = 2; i <= n ; i++) {
        bool = 1;

        for(int j = 2 ; j < i; j++){
            if( i % j == 0){
                bool = 0;
            }
        }
        liczba = i;

        if(bool == 1){
            while (liczba != 0){
                jednosci = liczba%10;
                liczba = liczba/10;

                if (jednosci >= liczba%10){
                    licznik += 1;

                }
                else {
                    licznik = 0;
                    break;
                }

            }

            if ( licznik != 0){
                printf("%d\n", i);

            }
        }
            
        
    }
}
    