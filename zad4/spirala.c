#include <stdio.h>

void spirala(int tab[], int n, int arr[n][n] );
void spirala(int tab[], int n, int arr[n][n] ){
    int gora = 0;
    int dol = n-1;
    int lewa = 0;
    int prawa = n-1;

    int indeks = 0;

    while (1) {
        if (lewa>prawa)
            break;

        //gorna krawedz
        for (int i = lewa; i<=prawa; i++){
            arr[gora][i] = tab[indeks++];
        }
        gora++;

        if (gora>dol)
            break;

        //prawa krawedz
        for (int i = gora; i <= dol; i++){
            arr[i][prawa] = tab[indeks++];
        }
        prawa--;

        if (lewa>prawa)
            break;

        //dolna krawedz
        for(int i = prawa; i>= lewa; i-- ){
            arr[dol][i] = tab[indeks++];
        }
        dol--;

        if (gora>dol)
            break;

        //lewa krawedz
        for (int i = dol; i>= gora; i--){
            arr[i][lewa] = tab[indeks++];
        }
        lewa++;
    }
}

void wypisywanie_spirali(int n, int arr[n][n]);
void wypisywanie_spirali(int n, int arr[n][n]){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf ("%d\t",arr[i][j] ) ;
        printf("\n");
    }
}

int main(void) {
    int n;
    printf("Podaj wymiar tablicy: ");
    scanf("%d", &n);

    // printf("%d", n);

    int tab[n*n];
    int arr[n][n];
    
    for (int i = 0; i<n*n; i++){
        tab[i] = i+1;
        printf("%d ", tab[i]);
    }

    printf("\n\n");

    

    spirala(tab, n, arr);
    wypisywanie_spirali(n, arr);


    return 0;
}
