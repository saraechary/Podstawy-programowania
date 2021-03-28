// Zadeklaruj i zaincjalizuj tablicę dziesięciu liczb całkowitych i tablicę dziesięciu liczb typu double, zadeklaruj 
// dwa wskaźniki jeden typu int, drugi double. Wypisz wartości i adresy wszystkich elementów obu tablic.  Przypisz adresy pierwszych 
// elementów tablic odpowiednim wskaźnikom i wypisz wartości i adresy wszystkich elementów tablic używając wskaźników.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void){

    int arrInt[10], *pointerInt;
    double arrDouble[10], *pointerDouble;
    
    srand((unsigned long)time(0));

    printf("Tablica INT:\n\n");
    for (int i = 0; i < 10; i++){
        arrInt[i] = rand()%30;
        pointerInt = &arrInt[i];
        printf("| indeks tablicy: %d | zawartosc tablicy: %d\t| adres komorki:  %p |\n",i, arrInt[i], pointerInt);
    }

    printf("\nTablica DOUBLE:\n\n");
    for (int i = 0; i < 10; i++){
        arrDouble[i] = rand()%30;
        pointerDouble = &arrDouble[i];
        printf("| indeks tablicy: %d | zawartosc tablicy: %.2lf\t| adres komorki:  %p |\n",i, arrDouble[i], pointerDouble);
    }

    return 0;

}