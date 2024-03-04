#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double numberHeight;
    double returnHeight = scanf("%lf", &numberHeight);

    double numberWeight;
    double returnWeight = scanf("%lf", &numberWeight);

    double imc = numberWeight / pow(numberHeight, 2);

    if (imc < 16)
    {
        printf("Magreza grave");
    }
    else if (imc >= 16 && imc < 17)
    {
        printf("Magreza moderada");
    }
    else if (imc >= 17 && imc < 18.5)
    {
        printf("Magreza leve");
    }
    else if (imc >= 18.5 && imc < 25)
    {
        printf("Saudavel");
    }
    else if (imc >= 25 && imc < 30)
    {
        printf("Sobrepeso");
    }
    else if (imc >= 30 && imc < 35)
    {
        printf("Obesidade Grau I");
    }
    else if (imc >= 35 && imc < 40)
    {
        printf("Obesidade Grau II (severa)");
    }
    else
    {
        printf("Obesidade Grau III (morbida)");
    }

       return 0;
}
