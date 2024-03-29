#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int e, int d)
{
    for (int i = e; i < d; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void troca(int *v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int particiona(int *v, int e, int d)
{
    int pivo = v[d - 1];
    int i = e - 1;
    for (int j = e; j < d - 1; j++)
    {
        if (v[j] <= pivo)
        {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i + 1, d - 1);
    printf("Pivo: [%d] %d\n", i + 1, pivo);
    imprimir(v, e, d);
    return i + 1;
}

void quickSortR(int *v, int e, int d)
{
    if (e < d - 1)
    {
        int p = particiona(v, e, d);
        quickSortR(v, e, p);
        quickSortR(v, p + 1, d);
    }
}

void quickSort(int *v, int n)
{
    quickSortR(v, 0, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *v = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    quickSort(v, n);
    imprimir(v, 0, n);
    free(v);
    return 0;
}
