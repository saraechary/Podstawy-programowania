#include <stdio.h>
#define max 256 

void silnia(int n);
int mnozenie_tablic(int arr[], int rozmiar, int x);

void silnia(int n){
    int arr[max];
    arr[0]=1;
    int rozmiar = 1;

    //licznie silni przy mnozeniu tablic
    for (int x = 2; x<=n; x++){
        rozmiar = mnozenie_tablic(arr, rozmiar, x);
    }

    //wypisywanie
    printf("Silnia z liczby %d wynosi \n", n);
    for (int i = rozmiar-1; i>=0; i--){
        printf("%d", arr[i]);
    }

}

int mnozenie_tablic(int arr[], int rozmiar, int x){
    int reszta = 0;
    int wartosc;

    for (int i = 0; i<rozmiar; i++){
        wartosc = arr[i]*x + reszta;
        //obliczenie liczby "jednosci" z liczby
        arr[i] = wartosc%10;
        //obliczenie liczby "dziesiatek"
        reszta = wartosc/10; 
    }
    // powiekszanie rozmiaru tablicy
    while (reszta >0){
        arr[rozmiar] = reszta%10;
        reszta /= 10;
        rozmiar++;
    }

    return rozmiar;
}


int main(void){
    int n;
    printf("Podaj liczbe z ktorej chcesz obliczyc silnie: ");
    scanf("%d", &n);

    silnia(n);

    return 0;

}