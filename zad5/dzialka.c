#include <stdio.h>
#include <stdlib.h>


void wypisywanie(int **arr, int n);
void wypisywanie(int **arr, int n){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf ("%d\t",arr[i][j] ) ;
        printf("\n");
    }
}

int czy_na_prawo(int **arr, int n, int i, int j);
int czy_na_prawo(int **arr, int n, int i, int j){

    for(int k = 0; k<n; k++){
        if (arr[i][j+k] == 1 || j+k == n){
            return (j+k);
        }
    }
}

void dzialka(int **arr, int n, int i, int j);
void dzialka(int **arr, int n, int i, int j){

    int max_prawo = n;
    int max = 0;

    int dlugosc_x =n;
    int dlugosc_y =0;

    for (int k =0; k<n; k++ ){
        if((i+k)<n){
            if (arr[i+k][j] !=1){
                dlugosc_y++;
                max_prawo = czy_na_prawo(arr, n, i+k ,j);
                
                if (max_prawo -j <= dlugosc_x)
                    dlugosc_x = max_prawo -j;  
            }

            else {
                dlugosc_y =0;
                break;
            }
        }

        if (dlugosc_x*dlugosc_y > max)
            max  = dlugosc_x*dlugosc_y;

    }
    arr[i][j] = max; 
    
}


int main(void) {
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

    printf("Twoja dzialka: \n");
    wypisywanie(arr, n);

    int max = 1; 
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (arr[i][j] != 1){
                dzialka(arr, n,i,j);
            }
            if (arr[i][j]>max)
                max = arr[i][j];
        }
    }

    printf("Najwieksze pole uzytkowego prostokatna wynosi %d", max);

}