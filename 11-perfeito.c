#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double numberA;
    double returnNumberA = scanf("%lf", &numberA);

    int numberControl = 0;

    for (int i = 1; numberA > numberControl; i++)
    {
        numberControl+=i;

        if (numberA == numberControl)
        {
            printf("SIM");
        }
        else if (numberA < numberControl)
        {
            printf("NAO");
        }
    }

        return 0;
}
