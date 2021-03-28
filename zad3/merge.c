// Zadeklaruj dwie tablice całkowite, t1 i t2 o długości N1 i N2 i wypełnij je liczbami losowymi z przedziału [0, 10)
// Napisz funkcję void reverse(int[], int), która odwraca jednowymiarową tablicę (pierwszy element staje się ostatnim, itd.).
// Napisz funkcję sortująca tablicę jednowymiarową i zastosuj ją do posortowania tablic t1 i t2.
// Napisz i przetestuj funkcję int one_two(int[], int, int[], int, int[]), która przyjmuje jako argumenty dwie posortowane 
// tablice liczb całkowitych i tworzy nową tablicę, której wartości będą pochodziły z przekazanych tablic, nie będą się powtarzały i 
// będą posortowane rosnąco. Funkcja zwraca długość tablicy wynikowej.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 100

void sortowanie(int arr[size], int n); //n - wielkosc tablicy
void sortowanie(int arr[size], int n){

    int zmiana;
    for (int i = 0 ; i < n-1; i++) {
        for (int j = 0 ; j < n-1; j++){
            if (arr[j] > arr[j+1]){
                zmiana = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = zmiana;
            }
        }
    }

    // printf("Posortowana tablica:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

}

void wypisanie_tablicy(int arr[size] , int n);
void wypisanie_tablicy(int arr[size] , int n){
    
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void reverse(int arr[size], int n );
void reverse(int arr[size], int n ){
    for (int i = n; i>0; i--){
        printf("%d ", arr[i-1]);
        }
    printf("\n");
}

int one_two(int arr1[size], int n1, int arr2[size], int n2, int arr_wynik[size] );
int one_two(int arr1[size], int n1, int arr2[size], int n2, int arr_wynik[size] ){

    int licznik = 0;
    for (int i = 0; i<= n1 +n2; i++ ){
        if (i<n1){
            arr_wynik[i] = arr1[i];
        }
        else {
            arr_wynik[i] = arr2[i-n1];
        }
    }
    for(int i = 0; i < (n2 + n1); i++){
        // printf("%d ", out[i]);
        licznik++;
    }
    return licznik;
    // wypisanie_tablicy(arr_wynik[size], n1+n2);
}

void duplikaty(int arr[size], int n);
void duplikaty(int arr[size], int n){

    if (n==1 || n==0) {
        printf("%d", n);
    }
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            if (arr[i] == arr[j]){ // jesli sa jakies duplikaty
                for (int k = j; k<n; k++) {//usuwamy duplikat
                    arr[k] = arr[k+1];
                }
                n--; //zmniejszmy tablice po usunieciu duplikatu

                j--; //jesli przesuwamy elementy nie zmienamy j
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\nOstateczna wielkosc tablicy: %d ", n);
}

int main(void) {
    int tablica1[size],  tablica2[size],  wynik[size];
    int wielkosc1, wielkosc2, wielkosc_wynik;

    srand((unsigned long)time(0));

    printf("Podaj wielkosc pierwszej tablicy: ");
    scanf("%d", &wielkosc1);
    for (int i=0; i<wielkosc1; i++){
        tablica1[i] = rand()%10;
    }
    printf("Twoja pierwsza tablica: ");
    wypisanie_tablicy(tablica1, wielkosc1);

    printf("\nPodaj wielkosc drugiej tablicy: ");
    scanf("%d", &wielkosc2);
    for (int i=0; i<wielkosc2; i++){
        tablica2[i] = rand()%10;
    }
    printf("Twoja druga tablica: ");
    wypisanie_tablicy(tablica2, wielkosc2);

    printf("\nTwoja pierwsza tablica odwrocona: ");
    reverse(tablica1, wielkosc1);

    printf("Twoja druga tablica odwrocona: ");
    reverse(tablica2, wielkosc2);

    printf("\nTwoja pierwsza tablica posegregowana: ");
    sortowanie(tablica1, wielkosc1);

    printf("\nTwoja druga tablica posegregowana: ");
    sortowanie(tablica2, wielkosc2);
    
    wielkosc_wynik = one_two(tablica1, wielkosc1, tablica2, wielkosc2, wynik);

    printf("\n\nPolaczenie obu tablic: \n");
    wypisanie_tablicy(wynik, wielkosc_wynik);

    printf("\nPolaczenie obu tablic posortowanych: \n");
    sortowanie(wynik, wielkosc_wynik);

    printf("\n\nPolaczenie obu tablic posortowanych bez duplikatow: \n");
    duplikaty(wynik, wielkosc_wynik);

    return 0;
}
