#include <stdio.h>

typedef struct
{
    int real;
    int imag;
} tComplex;

tComplex complexo(int real, int imag)
{
    tComplex c;
    c.real = real;
    c.imag = imag;
    return c;
}

tComplex soma(tComplex c1, tComplex c2)
{
    tComplex resultado;
    resultado.real = c1.real + c2.real;
    resultado.imag = c1.imag + c2.imag;
    return resultado;
}

tComplex subtrai(tComplex c1, tComplex c2)
{
    tComplex resultado;
    resultado.real = c1.real - c2.real;
    resultado.imag = c1.imag - c2.imag;
    return resultado;
}

tComplex multiplica(tComplex c1, tComplex c2)
{
    tComplex resultado;
    resultado.real = c1.real * c2.real - c1.imag * c2.imag;
    resultado.imag = c1.real * c2.imag + c1.imag * c2.real;
    return resultado;
}

tComplex divide(tComplex c1, tComplex c2)
{
    tComplex resultado;
    int divisor = c2.real * c2.real + c2.imag * c2.imag;
    if (divisor == 0)
    {
        printf("Divisão por zero não é permitida.\n");
        resultado.real = 0;
        resultado.imag = 0;
        return resultado;
    }
    resultado.real = (c1.real * c2.real + c1.imag * c2.imag) / divisor;
    resultado.imag = (c1.imag * c2.real - c1.real * c2.imag) / divisor;
    return resultado;
}

int main()
{
    tComplex c1, c2, resultado;
    char operador;
    int A, B, C, D;

    while (scanf("%d %di %c %d %di", &A, &B, &operador, &C, &D) != EOF)
    {
        c1 = complexo(A, B);
        c2 = complexo(C, D);

        switch (operador)
        {
        case '+':
            resultado = soma(c1, c2);
            break;
        case '-':
            resultado = subtrai(c1, c2);
            break;
        case '*':
            resultado = multiplica(c1, c2);
            break;
        case '/':
            resultado = divide(c1, c2);
            break;
        default:
            printf("Operador inválido.\n");
            continue;
        }

        printf("%d %di\n", resultado.real, resultado.imag);
    }

    return 0;
}
