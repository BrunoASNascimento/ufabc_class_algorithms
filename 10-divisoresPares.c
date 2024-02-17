#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double numberA;
    double returnNumberA = scanf("%lf", &numberA);

    int numberControl = 0;

    for (int i = 2; i <= numberA; i += 2)
    {

        if ((int)numberA % i == 0)
        {
            numberControl++;
        }
    }

    printf("%d", numberControl);

    return 0;
}
