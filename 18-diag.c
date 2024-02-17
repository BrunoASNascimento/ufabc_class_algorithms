/**
 * This program calculates the sum or average of the elements below the main diagonal of a square matrix.
 * The user is prompted to enter the type of calculation ('S' for sum or 'M' for average) and the size of the matrix.
 * Then, the user is asked to input the elements of the matrix.
 * The program calculates the sum or average of the elements below the main diagonal and prints the result.
 */

#include <stdio.h>

int main()
{
    char typeValue;
    scanf("%c", &typeValue);

    int N;
    scanf("%d", &N);

    int A[N][N];
    int countControl = 0;
    int sumValor = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);

            if (i > j)
            {
                countControl++;
                sumValor += A[i][j];
            }
        }
    }

    if (typeValue == 'S')
    {
        printf("%d\n", sumValor);
    }
    else if (typeValue == 'M')
    {
        printf("%.1f\n", (float)sumValor / countControl);
    }

    return 0;
}
