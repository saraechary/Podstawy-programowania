#include <stdlib.h>
#include <stdio.h>

void wypisywanie(int **arr, int n);
void wypisywanie(int **arr, int n){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf ("%d\t",arr[i][j] ) ;
        printf("\n");
    }
}

int obwod(int **arr, int i, int j, int n, int promien);
int obwod(int **arr, int i, int j, int n, int promien){
    int suma_obwodu = 0;

    int lewa = j -promien;
    int prawa = j + promien;
    int gora = i - promien;
    int dol = i + promien;

    for(int i = lewa; i<prawa; i++){
        suma_obwodu += arr[gora][i];
    }

    for(int i = prawa; i>lewa; i--){
        suma_obwodu += arr[dol][i];
    }

    for(int i = gora; i<dol; i++){
        suma_obwodu += arr[i][prawa];
    }

    for(int i = dol; i>gora; i--){
        suma_obwodu += arr[i][lewa];
    }

    return suma_obwodu;
}

int main(void){
    int n;

    printf("Podaj wymiar tablicy: ");
    scanf("%d", &n);

	int **arr = (int**)malloc(sizeof(int*)*n);

    for (int i = 0; i<n; i++){
        arr[i] = (int*)malloc(sizeof(int)*n);
        for (int j = 0; j<n; j++){
            // printf("Podaj elementy tablicy dla [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Twoja tablica 2d: \n");
    wypisywanie(arr, n);

    int o;
    printf("Podaj liczbe ile ma wynosic obwod: ");
    scanf("%d", &o);

    int licznik = 0;

    printf("Kwadraty maja srodki o indeksach: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for(int k = 1; k < n/2 + 1; k++){
                int suma;
                if (((i - k) >= 0) && ((i + k) < n) && ((j - k) >= 0) && ((j + k) < n)){
                    suma = obwod(arr, i, j, n, k);
                    // printf("Sum for arr[%d][%d] = %d\n",i,j,suma);

                    if (suma == o){
                        printf("%d %d\n", i, j);
                        licznik++;
                    }
                }
            }
        }
    }
    printf("Ilosc takich wystapien takich kwadratow: ");
    printf("%d\n", licznik);



    free(arr);
    return 0;
}