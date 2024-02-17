#include <stdio.h>

int main()
{
    int levelI;
    scanf("%d", &levelI);

    int levelJ;
    scanf("%d", &levelJ);

    int A[levelI][levelJ];

    for (int i = 0; i < levelI; i++)
    {
        for (int j = 0; j < levelJ; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < levelJ; i++)
    {
        for (int j = 0; j < levelI; j++)
        {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }

    return 0;
}
