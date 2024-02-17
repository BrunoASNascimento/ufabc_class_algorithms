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

int main()
{
    int A, B;

    scanf("%d %d", &A, &B);

    int resultado = mdc(A, B);

    printf("%d\n", resultado);

    return 0;
}
