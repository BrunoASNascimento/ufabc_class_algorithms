#include <stdio.h>

int main()
{
    signed long int numberValueA;
    signed long int returnValueA = scanf("%ld", &numberValueA);

    char nameValue[50];
    char returnNameValue = scanf("%s", &nameValue);

    signed long int numberValueB;
    signed long int returnValueB = scanf("%ld", &numberValueB);

    printf("%s, voce completa %d anos de idade neste ano.", nameValue, numberValueA - numberValueB);

    return 0;
}
