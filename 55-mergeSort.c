#include <stdio.h>
#include <stdlib.h>

void imprimir(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void intercala(int *v, int e, int m, int d)
{
    int *aux = malloc(sizeof(int) * (d - e));
    int i = e, j = m, k = 0;

    while (i < m && j < d)
    {
        if (v[i] < v[j])
        {
            aux[k++] = v[i++];
        }
        else
        {
            aux[k++] = v[j++];
        }
    }

    while (i < m)
    {
        aux[k++] = v[i++];
    }

    while (j < d)
    {
        aux[k++] = v[j++];
    }

    for (i = e, k = 0; i < d; i++, k++)
    {
        v[i] = aux[k];
    }

    imprimir(aux, d - e);
    free(aux);
}

void mergeSortR(int *v, int e, int d)
{
    if (d - e > 1)
    {
        int m = (e + d) / 2;
        mergeSortR(v, e, m);
        mergeSortR(v, m, d);
        intercala(v, e, m, d);
    }
}

void mergeSort(int *v, int n)
{
    mergeSortR(v, 0, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *v = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    mergeSort(v, n);
    free(v);
    return 0;
}
