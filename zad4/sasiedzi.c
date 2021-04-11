#include <stdlib.h>
#include <stdio.h>

void wypisywanie(int **arr, int n);
int sasiedzi(int **arr, int i, int j, int r, int n);

void wypisywanie(int **arr, int n){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf ("%d\t",arr[i][j] ) ;
        printf("\n");
    }
}

int sasiedzi(int **arr, int i, int j, int r, int n){
    int suma = 0;
    for (int k = (i - r); k < (r + i + 1); k++){
        for (int l = (j - r); l < (r + j + 1); l++){
            if (k >= 0 && k < n && l >= 0 && l < n){
                if(arr[k][l] == 1){
                    suma += 1;
                }
            }
        }
    }
    return suma;
}

int main(void){
    int n;

    printf("Podaj wymiar tablicy: ");
    scanf("%d", &n);

	int **arr = (int**)malloc(sizeof(int*)*n);

    for (int i = 0; i<n; i++){
        arr[i] = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j<n; j++){
            printf("Podaj elementy tablicy dla [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Twoja tablica 2d: \n");
    wypisywanie(arr, n);

    int r;
    printf("Podaj r: ");
    scanf("%d", &r);

    printf("Twoja tablica po operacji 'sasiedzi': \n");

    int **suma_sasiadow = (int**)malloc(sizeof(int*)*n);

    for (int i = 0; i < n; i++){
        suma_sasiadow[i] = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j < n; j++){
            suma_sasiadow[i][j] = sasiedzi(arr, i, j, r, (int)n);
            printf("%d  ", suma_sasiadow[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(suma_sasiadow);

}