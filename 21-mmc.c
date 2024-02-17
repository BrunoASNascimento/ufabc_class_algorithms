#include <stdio.h>

int mdc(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mmc(int a, int b)
{
    return (a / mdc(a, b)) * b;
}

int main()
{
    int A, B;

    scanf("%d %d", &A, &B);

    int resultado = mmc(A, B);

    printf("%d\n", resultado);

    return 0;
}
