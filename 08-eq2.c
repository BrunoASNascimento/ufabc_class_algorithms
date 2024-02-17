#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int numberValueA;
    int returnValueA = scanf("%d", &numberValueA);

    int numberValueB;
    int returnValueB = scanf("%d", &numberValueB);

    int numberValueC;
    int returnValueC = scanf("%d", &numberValueC);

    double  delta = pow(numberValueB, 2) - 4 * numberValueA * numberValueC;
    double  x1 = (-numberValueB + sqrt(delta)) / (2 * numberValueA);
    double  x2 = (-numberValueB - sqrt(delta)) / (2 * numberValueA);

    printf("%f %f", x1, x2);

    return 0;
}
