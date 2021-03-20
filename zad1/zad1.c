#include <stdio.h>

int main(void) {

    double a, p;
    int x;

    double netto, vat, brutto;

    printf("Podaj cene jednostkowa: ");
    scanf ("%lf", &a);
    printf("Cena jednostkowa = %.2lf\n", a );

    printf("Podaj liczbe zakupionych sztuk towaru: ");
    scanf ("%d", &x);
    printf("Liczba zakupionych sztuk towaru = %d\n", x);

    printf("Podaj wysokosc podatku VAT w procentach: ");
    scanf ("%lf" , &p);
    printf ("Wysokosc podatku VAT = %.2lf\n", p);

    netto = (double)a*x;
    vat = (double)netto*(p/100);
    brutto = netto+vat;
    printf ("\t----------------\n");
    printf ("\tPARAGON FISKALNY\n");
    printf ("\t----------------\n");


    printf ("KUPOWANA RZECZ:\t\t %.2lf x %d  %.2lf\n\n" , a, x, netto );
    printf ("OPODATKOWANIE:\t\t %.2lf\n\n", vat);
    printf ("SUMA:\t\t\t %.2lf", brutto);







    return 0;
}