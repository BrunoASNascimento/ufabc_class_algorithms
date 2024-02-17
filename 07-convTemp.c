#include <stdio.h>

int main()
{
    signed long int numberValueA;
    signed long int returnValueA = scanf("%ld", &numberValueA);

    int hourValue = numberValueA / 3600;
    int minuteValue = (numberValueA % 3600) / 60;
    int secondValue = (numberValueA % 3600) % 60;

    printf("%d:%d:%d", hourValue, minuteValue, secondValue);

    return 0;
}
