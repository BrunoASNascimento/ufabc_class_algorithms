#include <stdio.h>

int main()
{
    int numberA, smallerNumber;
    int firstNumber = 1; 

    while (1)
    {
        scanf("%d", &numberA);
        if (numberA < 0) 
            break;

        
        if (firstNumber)
        {
            smallerNumber = numberA;
            firstNumber = 0; 
        }
        else if (numberA < smallerNumber)
        { 
            smallerNumber = numberA;
        }
    }

    if (firstNumber)
    {
        printf("nenhum numero informado");
    }
    else
    {
        printf("%d", smallerNumber); 
    }

    return 0;
}
