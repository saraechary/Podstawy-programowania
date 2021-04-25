 // Program to convert Roman
// Numerals to Numbers
#include <stdio.h>
#include<string.h>

#define ARRSIZE 255

// This function returns value
// of a Roman symbol
int value(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;

	return -1;
}

// Returns decimal value of
// roman numaral
int toArabic(char str[])
{
	// Initialize result
	int wynik = 0;

	// Traverse given input
	for (int i = 0; i < strlen(str); i++)
	{
		// Getting value of symbol s[i]
		int s1 = value(str[i]);

		if (i + 1 < strlen(str))
		{
			// Getting value of symbol s[i+1]
			int s2 = value(str[i + 1]);

			// Comparing both values
			if (s1 >= s2)
			{
				// Value of current symbol
				// is greater or equal to
				// the next symbol
				wynik += s1;
			}
			else
			{
				// Value of current symbol is
				// less than the next symbol
				wynik = wynik + s2 - s1;
				i++;
			}
		}
		else {
			wynik += s1;
		}
	}
	return wynik;
}

char toRoman (int num){
    // int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    // char rom[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    // int i=12;   
    // while(n>0)
    // {
    //   int div = n/num[i];
    //   n = n%num[i];
    //   while(div--)
    //   {
    //     printf("%s", rom[i]);
    //   }
    //   i--;
    // }

    while(num != 0){

        if (num >= 1000)       // 1000 - m
        {
           printf("M");
           num -= 1000;
        }

        else if (num >= 900)   // 900 -  cm
        {
           printf("CM");
           num -= 900;
        }        

        else if (num >= 500)   // 500 - d
        {           
           printf("D");
           num -= 500;
        }

        else if (num >= 400)   // 400 -  cd
        {
           printf("CD");
           num -= 400;
        }

        else if (num >= 100)   // 100 - c
        {
           printf("C");
           num -= 100;                       
        }

        else if (num >= 90)    // 90 - xc
        {
           printf("XC");
           num -= 90;                                              
        }

        else if (num >= 50)    // 50 - l
        {
           printf("L");
           num -= 50;                                                                     
        }

        else if (num >= 40)    // 40 - xl
        {
           printf("XL");           
           num -= 40;
        }

        else if (num >= 10)    // 10 - x
        {
           printf("X");
           num -= 10;           
        }

        else if (num >= 9)     // 9 - ix
        {
           printf("IX");
           num -= 9;                         
        }

        else if (num >= 5)     // 5 - v
        {
           printf("V");
           num -= 5;                                     
        }

        else if (num >= 4)     // 4 - iv
        {
           printf("IV");
           num -= 4;                                                            
        }

        else if (num >= 1)     // 1 - i
        {
           printf("I");
           num -= 1;                                                                                   
        }
    }
}

// Driver Code
int main(void){

    char str1[ARRSIZE];
    char str2[ARRSIZE];
  
    printf("Twoja pierwsza liczba w zapisie rzymskim:\n");
    scanf("%s", str1);
    printf("Twoja druga liczba w zapisie rzymskim:\n");
    scanf("%s", str2);

    // char str[] = "MCMIV";
    // printf("%d", toArabic(str));

    // int number = 3549;
    // toRoman(number);

    printf("Suma podanych liczb zapisana w zapisie rzymskim:\n");
    printf("%c", toRoman(toArabic(str1)+toArabic(str2)));


	return 0;
}
